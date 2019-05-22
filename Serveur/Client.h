#pragma once

#include <QtWidgets>
#include <QtNetwork>
#include <QtCore>

class Client
{
	public:
		Client(QTcpSocket* socket = &QTcpSocket(), QString pseudo = "");
		Client(const Client& clientACopier);
		QString pseudo() const;
		quint16 tailleMessage() const;
		QTcpSocket* socket() const;
		void setTailleMessage(quint16 taille);
		void setSocket(QTcpSocket* socket);
		void setPseudo(const QString& pseudo);
		Client& operator=(Client const& clientACopier);

	private:
		QString* m_pseudo;
		quint16 m_tailleMessage;
		QTcpSocket* m_socket;
};

