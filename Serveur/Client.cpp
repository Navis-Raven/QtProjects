#include "Client.h"

Client::Client(QTcpSocket* socket, QString pseudo) : m_socket(socket), m_tailleMessage(0)
{
	m_pseudo = new QString(pseudo);
}

Client::Client(const Client& clientACopier)
{
	*this = clientACopier;
}


QString Client::pseudo() const
{
	return *m_pseudo;
}

quint16 Client::tailleMessage() const
{
	return m_tailleMessage;
}

QTcpSocket* Client::socket() const
{
	return m_socket;
}

void Client::setTailleMessage(quint16 taille)
{
	m_tailleMessage = taille;
}

void Client::setSocket(QTcpSocket* socket)
{
	m_socket = socket;
}

void Client::setPseudo(const QString& pseudo)
{
	*m_pseudo = pseudo;
}

Client& Client::operator=(Client const& clientACopier)
{
	if(this != &clientACopier)
	{
		m_tailleMessage = clientACopier.tailleMessage();
		*m_pseudo = clientACopier.pseudo();
		m_socket = clientACopier.socket();
	}

	return *this;
}

