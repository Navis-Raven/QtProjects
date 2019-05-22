#include "FenClient.h"
//#define DEBUG

FenClient::FenClient()
{
    setupUi(this);

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

    tailleMessage = 0;
	QRegExp rx_Pseudo("^[A-Za-z][A-Za-z0-9_]*$"); //les caractères de début '^' et de fin de chaînes '$' sont facultatifs dans ce cas présent
	QValidator* v_Pseudo = new QRegExpValidator(rx_Pseudo, this);
	pseudo->setValidator(v_Pseudo);
	listeDesPseudos = new QStringList();
	listModelPseudos = new QStringListModel(this);
	listViewConnectes->setModel(listModelPseudos);
	modeEnvoiMessage(false);


}

// Tentative de connexion au serveur
void FenClient::on_boutonConnexion_clicked()
{
 	if(estConnecte)
	{
		socket->abort();
		modeEnvoiMessage(false);
	}
	else
	{
		if(pseudo->text() == "")
		{
			QMessageBox::warning(this, tr("Erreur"), tr("Entrez un pseudo avant de lancer la connexion"));
			return;
		}
		// On annonce sur la fenêtre qu'on est en train de se connecter
		listeMessages->append(tr("<em>Tentative de connexion en cours...</em>"));
		boutonConnexion->setEnabled(false);

		socket->abort(); // On désactive les connexions précédentes s'il y en a
		socket->connectToHost(serveurIP->text(), serveurPort->value()); // On se connecte au serveur demandé
	}
}

void FenClient::envoyerMessage(const QString& messageAEnvoyer)
{
	QByteArray paquet;
	QDataStream out(&paquet, QIODevice::WriteOnly);

	out << (quint16)0;
	out << messageAEnvoyer;
	out.device()->seek(0);
	out << (quint16)(paquet.size() - sizeof(quint16));

	socket->write(paquet); // On envoie le paquet

	message->clear(); // On vide la zone d'écriture du message
	message->setFocus(); // Et on remet le curseur à l'intérieur
}
// Envoi d'un message au serveur
void FenClient::on_boutonEnvoyer_clicked()
{
	QString messageAEnvoyer = message->text();

	if(messageAEnvoyer != "")
	{
		envoyerMessage("[MSG]" + tr("<strong>") + pseudo->text() + tr("</strong> : ") + message->text());
	}
}

// Appuyer sur la touche Entrée a le même effet que cliquer sur le bouton "Envoyer"
void FenClient::on_message_returnPressed()
{
    on_boutonEnvoyer_clicked();
}

void FenClient::on_pseudo_returnPressed()
{
	on_boutonConnexion_clicked();
}

// On a reçu un paquet (ou un sous-paquet)
void FenClient::donneesRecues()
{
    
	
	/* Même principe que lorsque le serveur reçoit un paquet :
    On essaie de récupérer la taille du message
    Une fois qu'on l'a, on attend d'avoir reçu le message entier (en se basant sur la taille annoncée tailleMessage)
    */

	do
	{
		QDataStream in(socket);

		if (tailleMessage == 0)
		{
			if (socket->bytesAvailable() < (int)sizeof(quint16))
				 return;

			in >> tailleMessage;
		}

		if(socket->bytesAvailable() < tailleMessage)
			return;


		// Si on arrive jusqu'à cette ligne, on peut récupérer le message entier
		QString messageRecu;
		in >> messageRecu;

		//Traitement de la couche protocolaire
		QString prefixCode = messageRecu.mid(0, 5);
		messageRecu.remove(0, 5);

		#ifdef DEBUG
		listeMessages->append(prefixCode + "+" + messageRecu);
		#endif
		/*
		Code des messages échangés:
		[MSG] : message de tchat
		[INF] : information
		[LST] : liste des pseudos des personnes connectés
		[CON] : information d'un nouvel arrivant connecté
		[NCK] : envoi du nickname (pseudo) de l'utilisateur en cours vers le serveurs
		*/
		if(prefixCode == "[MSG]" || prefixCode == "[INF]")
		{
			// On affiche le message sur la zone de Chat
			listeMessages->append(messageRecu);
		}
		else if(prefixCode == "[LST]")
		{
			*listeDesPseudos = messageRecu.split(';');
			listModelPseudos->setStringList(*listeDesPseudos);
		}
		else if(prefixCode == "[CON]")
		{
			if(messageRecu != pseudo->text())
			{
				listeMessages->append(tr("<em><strong>") + messageRecu + tr("</strong> vient de se connecter</em>"));
			}
		}
		else
		{
			listeMessages->append(tr("<em>Erreur à la réception du message !</em>"));
		}
	
		// On remet la taille du message à 0 pour pouvoir recevoir de futurs messages
		tailleMessage = 0;
		#ifdef DEBUG
		listeMessages->append("BYTES AVAILABLE : " + QString::number(socket->bytesAvailable()));
		#endif
	}while(socket->bytesAvailable() > 0);
}

// Ce slot est appelé lorsque la connexion au serveur a réussi
void FenClient::connecte()
{
    listeMessages->append(tr("<em>Connexion réussie !</em>"));
	envoyerMessage("[NCK]" + pseudo->text());
    boutonConnexion->setEnabled(true);
	modeEnvoiMessage(true);
}

// Ce slot est appelé lorsqu'on est déconnecté du serveur
void FenClient::deconnecte()
{
    listeMessages->append(tr("<em>Déconnecté du serveur</em>"));
	modeEnvoiMessage(false);
}

// Ce slot est appelé lorsqu'il y a une erreur
void FenClient::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            listeMessages->append(tr("<em>ERREUR : le serveur n'a pas pu être trouvé. Vérifiez l'IP et le port.</em>"));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            listeMessages->append(tr("<em>ERREUR : le serveur a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP et le port.</em>"));
            break;
        case QAbstractSocket::RemoteHostClosedError:
            listeMessages->append(tr("<em>ERREUR : le serveur a coupé la connexion.</em>"));
            break;
        default:
            listeMessages->append(tr("<em>ERREUR : ") + socket->errorString() + tr("</em>"));
    }

    boutonConnexion->setEnabled(true);
}

void FenClient::modeEnvoiMessage(bool enable)
{
	if(enable)
	{
		boutonConnexion->setText(tr("&Deconnexion"));
		setWindowTitle("ZeroChat - " + pseudo->text());
	}
	else
	{
		boutonConnexion->setText(tr("&Connexion"));
		setWindowTitle("ZeroChat - Non connecté");
		//*listeDesPseudos = QStringList();
		listeDesPseudos->clear();
		listModelPseudos->setStringList(*listeDesPseudos);
		//listViewConnectes->setModel(listModelPseudos);
	}

	boutonEnvoyer->setEnabled(enable);
	message->setEnabled(enable);
	labelMessage->setEnabled(enable);
	pseudo->setEnabled(!enable);
	estConnecte = enable;
	listViewConnectes->setEnabled(enable);
}
