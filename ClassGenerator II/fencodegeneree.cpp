#include "fencodegeneree.h"

FenCodeGeneree::FenCodeGeneree(QString const& codeHeader, QString const & codeSource, QString const & nomHeader, QString const & nomSource, QWidget* p_Parent) : QDialog(p_Parent), m_nomHeader(nomHeader), m_nomSource(nomSource)
{
	setWindowTitle("Code Généré");
	setWindowIcon(QIcon("icone.png"));

	QVBoxLayout* p_vLayout_main = new QVBoxLayout;

	//1: Création d'un QTabWidget
	QTabWidget* p_onglets = new QTabWidget(this);

	//2: Création des onglets 
	QWidget* p_ongletHeader = new QWidget;
	QWidget* p_ongletSource = new QWidget;
	
	//3: Création du contenu des onglets
	m_p_codeHeader = new QTextEdit();
    m_p_codeHeader->setReadOnly(true);
	m_p_codeHeader->setFont(QFont("Courier"));
	m_p_codeHeader->setLineWrapMode(QTextEdit::NoWrap); //pour avoir une barre horizontale au lieu de réarranger le texte
	m_p_codeHeader->setPlainText(codeHeader);

	QHBoxLayout* p_hLayout_header = new QHBoxLayout;
	p_hLayout_header->addWidget(m_p_codeHeader);
	p_ongletHeader->setLayout(p_hLayout_header);

	m_p_codeSource = new QTextEdit();
	m_p_codeSource->setReadOnly(true);
	m_p_codeSource->setFont(QFont("Courier"));
	m_p_codeSource->setLineWrapMode(QTextEdit::NoWrap); //pour avoir une barre horizontale au lieu de réarranger le texte
	m_p_codeSource->setPlainText(codeSource);

	QHBoxLayout* p_hLayout_source = new QHBoxLayout;
	p_hLayout_source->addWidget(m_p_codeSource);
	p_ongletSource->setLayout(p_hLayout_source);

	//4: Ajout des onglets à p_onglets
	p_onglets->addTab(p_ongletHeader, "Header");
	p_onglets->addTab(p_ongletSource, "Source");
	
	//5: Final
	p_vLayout_main->addWidget(p_onglets);

    m_p_boutonFermer = new QPushButton("&Fermer");
	m_p_boutonEnregistrer = new QPushButton("&Enregistrer");
	m_p_boutonEnregistrer->setCursor(Qt::PointingHandCursor);
    m_p_boutonFermer->setCursor(Qt::PointingHandCursor);
	QHBoxLayout* p_hLayout_boutons = new QHBoxLayout;
	p_hLayout_boutons->addWidget(m_p_boutonEnregistrer);
	p_hLayout_boutons->addWidget(m_p_boutonFermer);

	QWidget::connect(m_p_boutonEnregistrer, SIGNAL(clicked()), this, SLOT(selectionnerDossier()));
    QWidget::connect(m_p_boutonFermer, SIGNAL(clicked()), this, SLOT(close()));
    p_vLayout_main->addLayout(p_hLayout_boutons);

	resize(400, 500);
    setLayout(p_vLayout_main);
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

void FenCodeGeneree::selectionnerDossier()
{
	//QString savFile = QFileDialog::getSaveFileName(this, QString(), "C:/");

	QString repertoire = QFileDialog::getExistingDirectory(this, QString(), "C:/");
	//QUrl repertoire = QFileDialog::getExistingDirectoryUrl(this, QString(), "C:/");
	QDir::setCurrent(repertoire);

	QFile* p_fichierHeader = new QFile(m_nomHeader);

	if(p_fichierHeader->open(QIODevice::WriteOnly))
	{
		//p_fichierHeader->write("blabla", qstrlen("blabla"));
		
		QTextStream stream(p_fichierHeader);
		stream << m_p_codeHeader->toPlainText() << endl;
	}
	else
	{
		return;
	}


	p_fichierHeader->close();

	QFile* p_fichierSource = new QFile(m_nomSource);

	if(p_fichierSource->open(QIODevice::WriteOnly))
	{
		QTextStream stream(p_fichierSource);
		stream << m_p_codeSource->toPlainText() << endl;
	}
	else
	{
		return;
	}
	
}

