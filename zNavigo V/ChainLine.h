#pragma once

#include <QtWidgets>

class ChainLine : public QObject //on le fait hériter de QObject pour hériter de la propriété de traçabilité du QObject parent
{
	public:
		ChainLine();
		ChainLine(QString const& title, QUrl const& url, QIcon const& icon = QIcon(), QDate const& date = QDate());
		ChainLine(ChainLine const& chainLine);
		~ChainLine();
		bool isNull() const;
		QUrl url() const;
		QDate date() const;
		QAction* action() const;
		void setNull();

		ChainLine& operator=(ChainLine const& hist);

	private:
		QUrl m_url;
		QDate m_date;
		QAction* m_action;
};

bool operator==(ChainLine const& a, ChainLine const& b);
bool operator!=(ChainLine const& a, ChainLine const& b);
