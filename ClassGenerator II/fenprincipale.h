#pragma once

#include <QtWidgets>


class FenPrincipale : public QWidget
{
	Q_OBJECT
	
	public:
        FenPrincipale();

	private slots:
		void genererCode();
		void setSource(QString const& nomClasse);
		void setHeader(QString const& nomClasse);

	signals:

	private:
		QLineEdit* m_p_nomClasse;
		QLineEdit* m_p_nomClasseMere;
		QLineEdit* m_p_nomSource;
		QLineEdit* m_p_nomHeader;
		QGroupBox* m_p_layoutGroup_AjoutCommentaires;
		QCheckBox* m_p_checkbox_pragmaOnce;
		QCheckBox* m_p_checkbox_GenConstructeur;
		QCheckBox *m_p_checkbox_GenDestructeur;
		QLineEdit* m_p_auteur;
		QTextEdit* m_p_roleDeLaClasse;
		QDateEdit* m_p_dateCreation;
		QPushButton* m_p_boutonQuitter;
		QPushButton* m_p_boutonGenerer;
};


