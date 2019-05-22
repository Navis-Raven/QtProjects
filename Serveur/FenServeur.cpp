#include "FenServeur.h"

FenServeur::FenServeur()
{
	setWindowTitle(tr("ZeroChat - Serveur"));
	
	// Création et disposition des widgets de la fenêtre
	etatServeur = new QLabel;
	nbClientsConnectesLabel = new QLabel;
	nbClientsConnectes = 0;
	majNbClientsConnectes();

	boutonQuitter = new QPushButton(tr("&Quitter"));
	connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(etatServeur);
	layout->addWidget(nbClientsConnectesLabel);
	layout->addWidget(boutonQuitter);
	setLayout(layout);

	// Gestion du serveur
	serveur = new QTcpServer(this);
	if(!serveur->listen(QHostAddress::Any, 50885)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
	{
		// Si le serveur n'a pas été démarré correctement
		etatServeur->setText(tr("Le serveur n'a pas pu être démarré. Raison :<br />") + serveur->errorString());
	}
	else
	{
		// Si le serveur a été démarré correctement
		etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter."));
		connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
	}
}

void FenServeur::nouvelleConnexion()
{
	Client* nouveauClient =  new Client(serveur->nextPendingConnection());
	clients << nouveauClient;

	connect(nouveauClient->socket(), SIGNAL(readyRead()), this, SLOT(donneesRecues()));
	connect(nouveauClient->socket(), SIGNAL(disconnected()), this, SLOT(deconnexionClient()));

	nbClientsConnectes++;
	majNbClientsConnectes();
}

void FenServeur::donneesRecues()
{
	int octetsDisponibles = 0;
	
	do
	{
		// 1 : on reçoit un paquet (ou un sous-paquet) d'un des clients

		// On détermine quel client envoie le message (recherche du QTcpSocket du client)
		QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
		if(socket == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
			return;

		Client* clientCourant = clients[trouverClient(socket)];
		quint16 tailleMessage = clientCourant->tailleMessage();

		// Si tout va bien, on continue : on récupère le message
		QDataStream in(socket);

		if(tailleMessage == 0) // Si on ne connaît pas encore la taille du message, on essaie de la récupérer
		{
			if(socket->bytesAvailable() < (int)sizeof(quint16)) // On n'a pas reçu la taille du message en entier
				return;

			in >> tailleMessage; // Si on a reçu la taille du message en entier, on la récupère
			clientCourant->setTailleMessage(tailleMessage);
		}

		// Si on connaît la taille du message, on vérifie si on a reçu le message en entier
		if(socket->bytesAvailable() < tailleMessage) // Si on n'a pas encore tout reçu, on arrête la méthode
			return;


		// Si ces lignes s'exécutent, c'est qu'on a reçu tout le message : on peut le récupérer !
		QString message;
		in >> message;

		QString prefixCode = message.mid(0, 5);

		if(prefixCode == "[NCK]")
		{
			message.remove(0, 5);
			clientCourant->setPseudo(message);
			envoyerATous("[CON]" + message);
			envoyerATous(listePseudos());
		}
		else
		{
			// 2 : on renvoie le message à tous les clients
			envoyerATous(message);
		}

		// 3 : remise de la taille du message à 0 pour permettre la réception des futurs messages
		tailleMessage = 0;
		clientCourant->setTailleMessage(tailleMessage);

		octetsDisponibles = socket->bytesAvailable();
	}while(octetsDisponibles > 0);
}

void FenServeur::deconnexionClient()
{
	// On détermine quel client se déconnecte
	QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
	if(socket == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
		return;

	int i = trouverClient(socket);

	envoyerATous("[INF]<em><strong>" + clients[i]->pseudo() + tr("</strong>vient de se déconnecter</em>"));
	clients.removeAt(i);
	envoyerATous(listePseudos());

	socket->deleteLater();
	nbClientsConnectes--;
	majNbClientsConnectes();
}

void FenServeur::envoyerATous(const QString &message)
{
	// Préparation du paquet
	QByteArray paquet;
	QDataStream out(&paquet, QIODevice::WriteOnly);

	out << (quint16)0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
	out << message; // On ajoute le message à la suite
	out.device()->seek(0); // On se replace au début du paquet
	out << (quint16)(paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message


	// Envoi du paquet préparé à tous les clients connectés au serveur
	for(int i = 0; i < clients.size(); i++)
	{
		clients[i]->socket()->write(paquet);
	}

}

void FenServeur::majNbClientsConnectes()
{
	nbClientsConnectesLabel->setText(tr("Nombre de clients connectés: <strong>") + QString::number(nbClientsConnectes));
}

int FenServeur::trouverClient(QTcpSocket* socket)
{
	for(int i = 0; i < clients.size(); i++)
	{
		if(clients[i]->socket() == socket)
			return i;
	}
	return -1;
}

QString FenServeur::listePseudos()
{
	QString liste = "[LST]";

	for(int i = 0; i < clients.size(); i++)
	{
		liste = liste + clients[i]->pseudo() + ";";
	}

	return liste;
}