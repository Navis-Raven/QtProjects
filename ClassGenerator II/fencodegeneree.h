#pragma once

#include <QtWidgets>

class FenCodeGeneree : public QDialog
{
	Q_OBJECT
	
	public:
		FenCodeGeneree(QString const& codeHeader, QString const & codeSource, QString const & nomHeader, QString const & nomSource, QWidget* p_Parent = 0);

	private slots:
		void selectionnerDossier();

	signals:

	private:
		QTextEdit* m_p_codeHeader;
		QTextEdit* m_p_codeSource;
		QString m_nomHeader;
		QString m_nomSource;
		QPushButton* m_p_boutonEnregistrer;
		QPushButton* m_p_boutonFermer;
};

