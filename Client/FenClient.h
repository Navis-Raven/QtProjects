#pragma once

#include <QtWidgets>
#include <QtNetwork>
#include "ui_FenClient.h"


class FenClient : public QWidget, private Ui::FenClientClass
{
	Q_OBJECT

public:
	FenClient();

private slots:
	void on_boutonConnexion_clicked();
	void on_boutonEnvoyer_clicked();
	void on_message_returnPressed();
	void on_pseudo_returnPressed();
	void donneesRecues();
	void connecte();
	void deconnecte();
	void erreurSocket(QAbstractSocket::SocketError erreur);

private:
	QTcpSocket *socket; // Représente le serveur
	quint16 tailleMessage;
	QStringList* listeDesPseudos;
	QStringListModel* listModelPseudos;
	bool estConnecte;
	inline void modeEnvoiMessage(bool enable);
	void envoyerMessage(const QString& messageAEnvoyer);
};
