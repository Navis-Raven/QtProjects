#include "fenprincipale.h"
#include "fencodegeneree.h"


FenPrincipale::FenPrincipale() : QWidget()
{
	setWindowTitle("Générateur de Classes");
	setWindowIcon(QIcon("icone.png"));

	QVBoxLayout* p_vLayout_main = new QVBoxLayout;
	QGroupBox* p_layoutGroup_DefClass = new QGroupBox("Définition de la classe", this);

	//Groupe "Définition de la Classe":
	m_p_nomClasse = new QLineEdit;
	m_p_nomClasseMere = new QLineEdit;
	m_p_nomSource = new QLineEdit;
	m_p_nomHeader = new QLineEdit;

	//m_p_nomSource->setReadOnly(true);
	//m_p_nomHeader->setReadOnly(true);

	QRegExp rx_Classe("^[A-Za-z][A-Za-z0-9_]*$"); //les caractères de début '^' et de fin de chaînes '$' sont facultatifs dans ce cas présent
	QValidator *v_Classe = new QRegExpValidator(rx_Classe, this);
	QRegExp rx_Source("^[A-Za-z][A-Za-z0-9_]*\\.cpp$"); //Il faut mettre un double backslash pour en avoir un car il passe à travers le filtre string de C++
	QValidator *v_Source = new QRegExpValidator(rx_Source, this);
	QRegExp rx_Header("^[A-Za-z][A-Za-z0-9_]*\\.h$");
	QValidator *v_Header = new QRegExpValidator(rx_Header, this);

	m_p_nomClasse->setValidator(v_Classe);
	m_p_nomClasseMere->setValidator(v_Classe);
	m_p_nomSource->setValidator(v_Source);
	m_p_nomHeader->setValidator(v_Header);

	//Pour débuger les validateurs il faut deconnecter le signal ci-dessous et faire des test avant de reconnecter plus tard

	QWidget::connect(m_p_nomClasse, SIGNAL(textEdited(QString)), this, SLOT(setSource(QString)));
	QWidget::connect(m_p_nomClasse, SIGNAL(textEdited(QString)), this, SLOT(setHeader(QString)));


	QFormLayout* p_formLayout_DeclarationClasses = new QFormLayout;
	p_formLayout_DeclarationClasses->addRow("&Nom de la classe :", m_p_nomClasse);
	p_formLayout_DeclarationClasses->addRow("Classe &mère :", m_p_nomClasseMere);
	p_formLayout_DeclarationClasses->addRow("Fichier &source :", m_p_nomSource);
	p_formLayout_DeclarationClasses->addRow("&Header :", m_p_nomHeader);

	p_layoutGroup_DefClass->setLayout(p_formLayout_DeclarationClasses);

	p_vLayout_main->addWidget(p_layoutGroup_DefClass);

	//Groupe options :
	QGroupBox* p_layoutGroup_options = new QGroupBox("Options", this);
	QVBoxLayout* p_vLayout_checkBoxes = new QVBoxLayout;

	m_p_checkbox_pragmaOnce = new QCheckBox("Protéger le &header des inclusions multiples");
	m_p_checkbox_pragmaOnce->setChecked(true);
	m_p_checkbox_GenConstructeur = new QCheckBox("Générer un &constructeur par défaut");
	m_p_checkbox_GenConstructeur->setChecked(true);
	m_p_checkbox_GenDestructeur = new QCheckBox("Générer un d&estructeur");

	p_vLayout_checkBoxes->addWidget(m_p_checkbox_pragmaOnce);
	p_vLayout_checkBoxes->addWidget(m_p_checkbox_GenConstructeur);
	p_vLayout_checkBoxes->addWidget(m_p_checkbox_GenDestructeur);

	p_vLayout_main->addWidget(p_layoutGroup_options);

	p_layoutGroup_options->setLayout(p_vLayout_checkBoxes);


	//Groupe "Ajouter des commentaires":
	m_p_layoutGroup_AjoutCommentaires = new QGroupBox("A&jouter des commentaires", this);
	m_p_layoutGroup_AjoutCommentaires->setCheckable(true);
	m_p_layoutGroup_AjoutCommentaires->setChecked(true);

	QFormLayout* p_formLayout_AjoutCommentaires = new QFormLayout;
	m_p_auteur = new QLineEdit;
	p_formLayout_AjoutCommentaires->addRow("&Auteur :", m_p_auteur);
	m_p_dateCreation =  new QDateEdit;
	m_p_dateCreation->setDate(QDate::currentDate());
	p_formLayout_AjoutCommentaires->addRow("&Date de création :", m_p_dateCreation);
	m_p_roleDeLaClasse = new QTextEdit;
	m_p_roleDeLaClasse->setAcceptRichText(false);
	p_formLayout_AjoutCommentaires->addRow("&Rôle de la classe :", m_p_roleDeLaClasse);


	m_p_layoutGroup_AjoutCommentaires->setLayout(p_formLayout_AjoutCommentaires);

	p_vLayout_main->addWidget(m_p_layoutGroup_AjoutCommentaires);

	//Boutons Quitter/Générer :
	QHBoxLayout* p_hLayout_boutons = new QHBoxLayout;
	p_hLayout_boutons->setDirection(QBoxLayout::RightToLeft);

	m_p_boutonQuitter = new QPushButton("&Quitter");
	m_p_boutonQuitter->setCursor(Qt::PointingHandCursor);
	QWidget::connect(m_p_boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
	p_hLayout_boutons->addWidget(m_p_boutonQuitter);

	m_p_boutonGenerer = new QPushButton("&Générer");
	m_p_boutonGenerer->setCursor(Qt::PointingHandCursor);

	QWidget::connect(m_p_boutonGenerer, SIGNAL(clicked()), this, SLOT(genererCode()));

	p_hLayout_boutons->addWidget(m_p_boutonGenerer);

	p_hLayout_boutons->setAlignment(Qt::AlignRight);

	p_vLayout_main->addLayout(p_hLayout_boutons);

	setLayout(p_vLayout_main);
}

void FenPrincipale::genererCode()
{
	
	if (m_p_nomClasse->text().isEmpty())
	{
		QMessageBox::warning(this, "Erreur", "Vous n'avez pas entré le nom de la Classe !");
		return;
	}

	QString commentaires = "";
	
	if(m_p_layoutGroup_AjoutCommentaires->isChecked())
	{
		commentaires += "/*\n";

		if(!m_p_auteur->text().isEmpty())
		{
			commentaires += " * Auteur: " + m_p_auteur->text() + "\n";
		}
		
		commentaires += " * Date de creation: " + m_p_dateCreation->text() + "\n";

		if(!m_p_roleDeLaClasse->toPlainText().isEmpty())
		{
			commentaires += " * Role de la classe: " + m_p_roleDeLaClasse->toPlainText() + "\n";
		}
		
		commentaires += " */\n\n";

	}

	//Header
	QString codeHeader = "";

	codeHeader += commentaires;
	
	if(m_p_checkbox_pragmaOnce->isChecked())
	{
		codeHeader += "#pragma once \n\n";
	}
	
	codeHeader += "class " + m_p_nomClasse->text();

	
	if(!m_p_nomClasse->text().isEmpty())
	{
		codeHeader += " : public " + m_p_nomClasseMere->text();
	}

	codeHeader += "\n";
	codeHeader += "{\n";
	codeHeader += "    public:\n";

	if(m_p_checkbox_GenConstructeur->isChecked())
	{
		codeHeader += "        " + m_p_nomClasse->text() + "();\n";
	}

	if (m_p_checkbox_GenDestructeur->isChecked())
	{
		codeHeader += "        ~" +  m_p_nomClasse->text() + "();\n";
	}

	codeHeader += "\n";
	codeHeader += "    private:\n\n";
	codeHeader += "};\n\n";


	//Source
	QString codeSource = "";

	codeSource += commentaires;

	codeSource += "#include \"" + m_p_nomHeader->text() + "\"\n\n";
	if (m_p_checkbox_GenConstructeur->isChecked())
	{
		codeSource += m_p_nomClasse->text() + "::" + m_p_nomClasse->text() + "()\n";
		codeSource += "{\n";
		codeSource += "}\n\n";
	}

	if (m_p_checkbox_GenDestructeur->isChecked())
	{
		codeSource += m_p_nomClasse->text() + "::~" + m_p_nomClasse->text() + "()\n";
		codeSource += "{\n";
		codeSource += "}\n\n";
	}

	FenCodeGeneree FenetreCodeGeneree(codeHeader, codeSource, m_p_nomHeader->text(),  m_p_nomSource->text(), this);
	FenetreCodeGeneree.exec();
}

void FenPrincipale::setSource(QString const& nomClasse)
{
	m_p_nomSource->setText(nomClasse + ".cpp");
}
void FenPrincipale::setHeader(QString const& nomClasse)
{
	m_p_nomHeader->setText(nomClasse + ".h");
}

