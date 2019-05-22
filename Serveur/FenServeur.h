#pragma once

#include <QtWidgets>
#include <QtNetwork>
#include <QtCore>
#include "Client.h"

class FenServeur : public QWidget
{
	Q_OBJECT

public:
	FenServeur();
	void envoyerATous(const QString &message);

private slots:
	void nouvelleConnexion();
	void donneesRecues();
	void deconnexionClient();

private:
	QLabel* etatServeur;
	QLabel* nbClientsConnectesLabel;
	qint16 nbClientsConnectes;
	QPushButton* boutonQuitter;

	QTcpServer* serveur;
	QList<Client*> clients;

	inline void majNbClientsConnectes();
	inline int trouverClient(QTcpSocket* socket);
	inline QString listePseudos();
};
