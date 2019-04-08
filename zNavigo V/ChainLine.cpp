#include "ChainLine.h"


ChainLine::ChainLine() : QObject(), m_url(""), m_date(QDate())
{
	m_action = new QAction();
}


ChainLine::ChainLine(QString const& titre, QUrl const& url, QIcon const& icon, QDate const& date) : QObject(), m_url(url), m_date(date)
{
	m_action = new QAction(titre, this);
	m_action->setIcon(icon);
}

ChainLine::ChainLine(ChainLine const& chainLine) 
{
	*this = chainLine; //voir operator=
}

ChainLine::~ChainLine()
{
	//les QAction héritent de QObject et dont la destruction est géré par Qt
	//De plus ChainLine hérite de QObject
}


bool ChainLine::isNull() const
{
	return m_date.isNull();
}

void ChainLine::setNull()
{
	m_date = QDate();
}

QUrl ChainLine::url() const
{
	return m_url;
}

QDate ChainLine::date() const
{
	return m_date;
}

QAction* ChainLine::action() const
{
	return m_action;
}

ChainLine& ChainLine::operator=(ChainLine const& hist)
{
	m_url = hist.url();
	m_date = hist.date();
	m_action = new QAction(hist.action()->text(), this); //les pointeur parents ne doivent pas être les mêmes pour qu'en cas de destruction de l'un par Qt, l'autre action est tjs là
	m_action->setIcon(hist.action()->icon());

	return *this;
}

bool operator==(ChainLine const& a, ChainLine const& b)
{
	return a.url().toString() == b.url().toString();
}

bool operator!=(ChainLine const& a, ChainLine const& b)
{
	return a.url().toString() != b.url().toString();
}
