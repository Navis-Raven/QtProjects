#include "FenPrincipale.h"

FenPrincipale::FenPrincipale(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this); 

	m_parametres = new QSettings("zNavConf.ini", QSettings::IniFormat);

	m_fenParametres = new FenParametres(m_parametres->value("PageDAcceuil", "https://www.google.com").toString(), m_parametres->value("ActiverHistorique", true).toBool(), this);

	setWindowTitle("zNavigo");
	setWindowIcon(QIcon("znavigo_icones/web.png"));

	ui.actionPage_pr_c_dente->setIcon(QIcon("znavigo_icones/prec.png"));
	ui.mainToolBar->addAction(ui.actionPage_pr_c_dente);

	ui.actionPage_suivante->setIcon(QIcon("znavigo_icones/suiv.png"));
	ui.mainToolBar->addAction(ui.actionPage_suivante);

	ui.actionArr_ter_le_chargement->setIcon(QIcon("znavigo_icones/stop.png"));
	ui.mainToolBar->addAction(ui.actionArr_ter_le_chargement);

	ui.action_Actualiser->setIcon(QIcon("znavigo_icones/actu.png"));
	ui.mainToolBar->addAction(ui.action_Actualiser);

	ui.actionPage_d_a_cceuil->setIcon(QIcon("znavigo_icones/home.png"));
	ui.mainToolBar->addAction(ui.actionPage_d_a_cceuil);

	ui.mainToolBar->addSeparator();

	m_defaultFavTxt = ui.action_Ajouter_aux_favoris->text();
	changerFavActMode(ajouter);
	ui.mainToolBar->addAction(ui.action_Ajouter_aux_favoris);

	m_barreAdresse = new QLineEdit("", this);
	ui.mainToolBar->addWidget(m_barreAdresse);
	m_actionAllerA = new QAction("A&ller à...");
	m_actionAllerA->setIcon(QIcon("znavigo_icones/go.png"));
	ui.mainToolBar->addAction(m_actionAllerA);

	connect(m_actionAllerA, SIGNAL(triggered()), this, SLOT(allerA()));
	connect(m_barreAdresse, SIGNAL(returnPressed()), this, SLOT(allerA()));
	
	QVBoxLayout* vLayout = new QVBoxLayout;

	//Création d'un QTabWidget
	m_onglets = new QTabWidget;
	m_onglets->setMovable(true);
	m_onglets->setTabsClosable(true);
	m_onglets->setTabShape(QTabWidget::Triangular);

	m_plusTab = new QPushButton("+");
	m_plusTab->setFixedSize(30, 20);
	m_onglets->setCornerWidget(m_plusTab);
	connect(m_plusTab, SIGNAL(clicked()), this, SLOT(on_actionNouvel_onglet_triggered()));

	//Création de l'onglet par défaut et son contenu:
	on_actionNouvel_onglet_triggered();

	m_onglets->setStyleSheet("QTabBar::tab{width:150px; height: 25px;}");
	m_onglets->setElideMode(Qt::ElideRight); //mettre les "..." si le titre est trop long


	this->setCentralWidget(m_onglets);

	m_chargement = new QProgressBar;
	m_chargement->setFixedHeight(20);
	m_chargement->setMaximumWidth(200);
	m_chargement->setValue(0); 
	m_statusBar = new QStatusBar;
	m_statusBar->addPermanentWidget(m_chargement, 0); //pour aligner à droite
	this->setStatusBar(m_statusBar);

	connect(m_onglets, SIGNAL(tabCloseRequested(int)), this, SLOT(fermeLOnglet(int)));
	connect(m_onglets, SIGNAL(currentChanged(int)), this, SLOT(ongletChange()));

	m_fenetreChercher = new SearchDialog(this);
	m_fenetreChercher->setWindowIcon(this->windowIcon());
	connect(m_fenetreChercher, SIGNAL(boutonPrecSignal()), this, SLOT(occurencePrecedente()));
	connect(m_fenetreChercher, SIGNAL(boutonSuivSignal()), this, SLOT(occurenceSuivante()));
	connect(m_fenetreChercher, SIGNAL(signalTextChange()), this, SLOT(occurenceSuivante()));
	connect(m_fenetreChercher, SIGNAL(finished(int)), this, SLOT(resetChercher()));

	m_fenParametres->setWindowIcon(this->windowIcon());
	connect(m_fenParametres, SIGNAL(effacerFavSingal()), this, SLOT(on_action_Effacer_la_liste_des_favoris_triggered()));
	connect(m_fenParametres, SIGNAL(effacerHistSignal()), this, SLOT(on_action_Effacer_historique_triggered()));
	connect(m_fenParametres, SIGNAL(historiqueDesactive()), this, SLOT(gererSignalHistoriqueDesactive()));
	connect(m_fenParametres, SIGNAL(nouveauxParametres()), this, SLOT(sauverNouveauxParametres()));

	//Initialisations:
	m_vuePrecedente = nullptr;
	m_hisBuffer = new ChainList(MAX_HIST);
	m_favBuffer = new ChainList(MAX_FAV, false);
	restaurerHisFav();
	sauverNouveauxParametres();
	ongletChange();
}

void FenPrincipale::changerFavActMode(FavActMode mode)
{
	switch(mode)
	{
		case ajouter: 
			ui.action_Ajouter_aux_favoris->setIcon(QIcon("znavigo_icones/fav_white.png"));
			ui.action_Ajouter_aux_favoris->setText(m_defaultFavTxt);
			m_favActMode_ajouter = true;
			break;
		case erreur_ajout: 
			ui.action_Ajouter_aux_favoris->setIcon(QIcon("znavigo_icones/fav_red.png"));
			break;
		case retirer: 
			ui.action_Ajouter_aux_favoris->setIcon(QIcon("znavigo_icones/fav_yellow.png"));
			ui.action_Ajouter_aux_favoris->setText("Retirer des favoris");
			m_favActMode_ajouter = false;
			break;
	}
}


 QWebEngineView* FenPrincipale::pageActuelle()
{
	return ((QWebEngineView*) m_onglets->currentWidget());
}

void FenPrincipale::configureView(QWebEngineView* view)
{
	QWebEngineSettings* sett = view->settings();
	//sett->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true); //Complexe à mettre en oeuvre
	sett->setAttribute(QWebEngineSettings::JavascriptCanAccessClipboard, true);
	sett->setAttribute(QWebEngineSettings::SpatialNavigationEnabled, true);
	sett->setAttribute(QWebEngineSettings::ScrollAnimatorEnabled, true);
	sett->setAttribute(QWebEngineSettings::PluginsEnabled, true);
	sett->setAttribute(QWebEngineSettings::WebGLEnabled, true);
	sett->setAttribute(QWebEngineSettings::Accelerated2dCanvasEnabled, true);
	sett->setAttribute(QWebEngineSettings::TouchIconsEnabled, true);
	sett->setAttribute(QWebEngineSettings::AllowWindowActivationFromJavaScript, true);
	sett->setAttribute(QWebEngineSettings::JavascriptCanPaste, true);
}
void FenPrincipale::on_actionNouvel_onglet_triggered()
{
	m_count_tabs = m_onglets->count();
	
	QWebEngineView* view = new QWebEngineView(this);
	configureView(view);
	view->load(m_fenParametres->pageDAccueil());
	int currentIndex = m_onglets->addTab(view, "New tab...");
	m_onglets->setCurrentIndex(currentIndex);
	connect(view, SIGNAL(loadFinished(bool)), this, SLOT(titrerLOnglet(bool)));
	connect(view, SIGNAL(iconChanged(QIcon)), this, SLOT(iconerLOnglet(QIcon)));
	m_count_tabs = m_onglets->count();
	
}

void FenPrincipale::ajouterALHistorique(QString const& titre, QUrl const& url,  QDate const& date, QIcon const& icon)
{
	if(m_fenParametres->etatActiverHistorique())
	{
		ChainLine chainLine(titre, url, icon, date);
		QAction* act = nullptr;

		ui.action_vide->setVisible(false);

		act = m_hisBuffer->append(chainLine);
		act->setIcon(icon);

		ui.menu_Historique->addAction(act);
		connect(act, SIGNAL(triggered()), this, SLOT(chargerHistorique()));
	}
}


void FenPrincipale::titrerLOnglet(bool etat_OK)
{
	QWebEngineView* view = (QWebEngineView*) sender(); //obtenir un pointeur de l'émetteur

	int viewIndex = m_onglets->indexOf(view); //obtenir l'index du view émetteur

	if(etat_OK)
	{
		m_onglets->setTabText(viewIndex, view->title());
		ajouterALHistorique(view->title(), view->url(), QDate::currentDate());
	}
	else
	{
		m_onglets->setTabText(viewIndex, "Loading...");
	}
}

void FenPrincipale::iconerLOnglet(const QIcon& icon)
{
	QWebEngineView* view = (QWebEngineView*) sender(); //obtenir un pointeur de l'émetteur
	int viewIndex = m_onglets->indexOf(view); //obtenir l'index du view émetteur
	m_onglets->setTabIcon(viewIndex, view->icon());
	ajouterALHistorique(view->title(), view->url(), QDate::currentDate(), icon);
}

void FenPrincipale::controleFavVide()
{
	if(m_favBuffer->isVoid())
	{
		ui.action_vide_2->setVisible(true);
	}
	else
	{
		ui.action_vide_2->setVisible(false);
	}
}

void FenPrincipale::controleFavActMode()
{
	if(m_favBuffer->exists(pageActuelle()->url()))
	{
		changerFavActMode(retirer);
	}
	else
	{
		changerFavActMode(ajouter);
	}
}

void FenPrincipale::creerUnFavoris(QAction* act, QIcon const& icon)
{
	act->setIcon(icon);
	ui.menu_Favoris->addAction(act);
	QMenu* menu = new QMenu(this);
	QAction* allerA = new QAction("Aller à...", act);
	QAction* effacerFav = new QAction("Effacer", act);
	menu->addAction(allerA);
	menu->addAction(effacerFav);
	act->setMenu(menu);
	connect(allerA, SIGNAL(triggered()), this, SLOT(chargerFavori()));
	connect(effacerFav, SIGNAL(triggered()), this, SLOT(effacerUnFavori()));
}

void FenPrincipale::on_action_Ajouter_aux_favoris_triggered()
{
	ChainLine fav(pageActuelle()->title(), pageActuelle()->url(), pageActuelle()->icon());
	
	if(m_favActMode_ajouter)
	{ 
		QAction* act = m_favBuffer->append(fav);
		
		if(act == nullptr)
		{
			changerFavActMode(erreur_ajout);
			QString message("Impossible d'ajouter ce favori car vous avez enregistré le maximum de favoris possibles: " + QString::number(m_favBuffer->max()));
			message += "\nRetirez des favoris existants pour pouvoir en rajouter d'autres !";
			QMessageBox::warning(this, "Erreur", message);
		}
		else
		{
			creerUnFavoris(act, pageActuelle()->icon());
			changerFavActMode(retirer);
		}
	}
	else
	{
		m_favBuffer->remove(fav);
		changerFavActMode(ajouter);
	}

	controleFavVide();
}

void FenPrincipale::effacerUnFavori()
{
	QAction* actionEffacer = (QAction*) sender();
	QAction* actionFavoris = (QAction*) actionEffacer->parent();
	ChainLine* chainLineToRemove = (ChainLine*) actionFavoris->parent();

	m_favBuffer->remove(*chainLineToRemove);
	controleFavVide();
	controleFavActMode();
}

void FenPrincipale::on_action_Effacer_la_liste_des_favoris_triggered()
{
	int	ans = QMessageBox::warning(this, "Attention !", "Vous êtes sur le point d'effacer tous vos favoris !\nEtes vous sûrs de vouloir continuer ?", QMessageBox::Cancel | QMessageBox::Ok);
	if (ans == (QMessageBox::Cancel)) return;

	while (!m_favBuffer->isVoid())
	{
		m_favBuffer->popOutFirstIn();
	}

	changerFavActMode(ajouter);
	ui.action_vide_2->setVisible(true);
}

FenPrincipale::EffHistRet FenPrincipale::on_action_Effacer_historique_triggered()
{
	int	ans = QMessageBox::warning(this, "Attention !", "Vous êtes sur le point d'effacer l'historique des sites web visités !\nEtes vous sûrs de vouloir continuer ?", QMessageBox::Cancel | QMessageBox::Ok);
	if (ans == (QMessageBox::Cancel)) return annule;
	
	if (m_hisBuffer->isVoid())
	{
		return vide;
	}
	while (!m_hisBuffer->isVoid())
	{
		m_hisBuffer->popOutFirstIn();
	}

	ui.action_vide->setVisible(true);
	return fait;
}

void FenPrincipale::gererSignalHistoriqueDesactive()
{
	EffHistRet ret = on_action_Effacer_historique_triggered();

	if(ret == annule)
	{
		//On rétablit la case cochée
		m_fenParametres->setActiverHistorique(true);
	}
}

void FenPrincipale::chargerHistorique()
{
	QAction* action = (QAction*) sender(); //obtenir un pointeur de l'émetteur
	ChainLine* chainLine = (ChainLine*) action->parent(); //obtenir le pointeur vers l'chainLine parent de l'action

	on_actionNouvel_onglet_triggered();
	pageActuelle()->load(chainLine->url());
}

void FenPrincipale::chargerFavori()
{
	QAction* action = (QAction*)sender(); //obtenir un pointeur de l'émetteur
	ChainLine* chainLine = (ChainLine*)action->parent()->parent(); //obtenir le pointeur vers l'chainLine parent de l'action

	on_actionNouvel_onglet_triggered();
	pageActuelle()->load(chainLine->url());
}

void FenPrincipale::fermeLOnglet(int index)
{
	if (m_onglets->count() == 1)
	{
		pageActuelle()->load(m_fenParametres->pageDAccueil());
	}
	else
	{
		m_onglets->removeTab(index);
	}
	m_count_tabs = m_onglets->count();
}

void FenPrincipale::chargementCommence()
{
	m_chargement->reset();
	m_chargement->setVisible(true);
	ajournerBarreAdresse();
}

void FenPrincipale::chargementTermine()
{
	m_chargement->setVisible(false);
	m_statusBar->showMessage("Prêt", 2000);
	ajournerBarreAdresse();
}


void FenPrincipale::on_actionFermer_onglet_triggered()
{
	fermeLOnglet(m_onglets->currentIndex());
}

void FenPrincipale::on_actionPage_pr_c_dente_triggered()
{
	pageActuelle()->back();
}

void FenPrincipale::on_actionPage_suivante_triggered()
{
	pageActuelle()->forward();
}

void FenPrincipale::on_action_Actualiser_triggered()
{
	pageActuelle()->reload();
}

void FenPrincipale::on_actionArr_ter_le_chargement_triggered()
{
	pageActuelle()->stop();
}

void FenPrincipale::on_actionPage_d_a_cceuil_triggered()
{
	pageActuelle()->load(m_fenParametres->pageDAccueil());
}

void FenPrincipale::on_action_Fermer_triggered()
{
	qApp->quit();
}

void FenPrincipale::on_action_A_propos_triggered()
{
	QMessageBox::information(this, "A propos...", "zNavigo version 5.0 2019");
}

void FenPrincipale::on_actionA_porpos_de_Qt_triggered()
{
	QMessageBox::information(this, "A propos de Qt...", "Ce programme utilise la version 5.12.0 de Qt");

}

void FenPrincipale::on_action_Rechercher_triggered()
{
	QString displayText("");

	displayText = pageActuelle()->selectedText();

	m_fenetreChercher->setTexteAChercher(displayText);
	m_fenetreChercher->show();
}

void FenPrincipale::on_action_Param_tres_triggered()
{
	m_fenParametres->exec();
}

void FenPrincipale::occurencePrecedente()
{
	QFlags<QWebEnginePage::FindFlag> flags = QWebEnginePage::FindBackward;
	if(m_fenetreChercher->repecterLaCasse()) flags |= QWebEnginePage::FindCaseSensitively;
	pageActuelle()->findText(m_fenetreChercher->texteAChercher(), flags);
}

void FenPrincipale::occurenceSuivante()
{
	QFlags<QWebEnginePage::FindFlag> flags = 0;
	if (m_fenetreChercher->repecterLaCasse()) flags |= QWebEnginePage::FindCaseSensitively;
	pageActuelle()->findText(m_fenetreChercher->texteAChercher(), flags);
}

void FenPrincipale::resetChercher()
{
	pageActuelle()->findText("");
}

void FenPrincipale::allerA()
{
	QString adresse = "";
	adresse = m_barreAdresse->text();

	if (!(adresse.startsWith("http://") || adresse.startsWith("https://")))
	{
		adresse.prepend("https://");
	}

	m_barreAdresse->setText(adresse);
	pageActuelle()->load(adresse);
}

void FenPrincipale::ongletChange()
{
	disconnect(m_vuePrecedente, SIGNAL(loadStarted()), this, SLOT(chargementCommence()));
	disconnect(m_vuePrecedente, SIGNAL(loadProgress(int)), m_chargement, SLOT(setValue(int)));
	disconnect(m_vuePrecedente, SIGNAL(loadFinished(bool)), this, SLOT(chargementTermine()));

	connect(pageActuelle(), SIGNAL(loadStarted()), this, SLOT(chargementCommence()));
	connect(pageActuelle(), SIGNAL(loadProgress(int)), m_chargement, SLOT(setValue(int)));
	connect(pageActuelle(), SIGNAL(loadFinished(bool)), this, SLOT(chargementTermine()));
	
	m_vuePrecedente = pageActuelle();

	ajournerBarreAdresse();
}

void FenPrincipale::ajournerBarreAdresse()
{
	m_barreAdresse->setText(pageActuelle()->url().toString());
	m_barreAdresse->setCursorPosition(0);

	controleFavActMode();
}

void FenPrincipale::sauverNouveauxParametres()
{
	m_parametres->setValue("etatActiverHistorique", m_fenParametres->etatActiverHistorique());
	m_parametres->setValue("pageDAcceuil", m_fenParametres->pageDAccueil());
}
 
void FenPrincipale::restaurerHisFav()
{
	QList<QVariant> emptyList; //liste par defaut

	QList<QVariant> urlListHis = m_parametres->value("urlListHis", emptyList).toList();
	QList<QVariant> urlTitleListHis = m_parametres->value("urlTitleListHis", emptyList).toList();
	QList<QVariant> dateListHis = m_parametres->value("dateListHis", emptyList).toList();
	QList<QVariant> iconHis = m_parametres->value("iconHis", emptyList).toList();

	QList<QVariant> urlListFav = m_parametres->value("urlListFav", emptyList).toList();
	QList<QVariant> urlTitleListFav = m_parametres->value("urlTitleListFav", emptyList).toList();
	QList<QVariant> iconFav = m_parametres->value("iconFav", emptyList).toList();

	QUrl urlToRestore;
	QString titleToRestore;
	QIcon iconToRestore;
	QDate dateToRestore;

	while(!urlListHis.isEmpty())
	{
		urlToRestore = urlListHis.first().toString();
		urlListHis.removeFirst();
		titleToRestore = urlTitleListHis.first().toString();
		urlTitleListHis.removeFirst();
		iconToRestore = iconHis.first().value<QIcon>();
		iconHis.removeFirst();
		dateToRestore = dateListHis.first().toDate();
		dateListHis.removeFirst();

		ajouterALHistorique(titleToRestore, urlToRestore, dateToRestore, iconToRestore);
	}

	while (!urlListFav.isEmpty())
	{
		urlToRestore = urlListFav.first().toString();
		urlListFav.removeFirst();
		titleToRestore = urlTitleListFav.first().toString();
		urlTitleListFav.removeFirst();
		iconToRestore = iconFav.first().value<QIcon>();
		iconFav.removeFirst();
		
		QAction* act = m_favBuffer->append(ChainLine(titleToRestore, urlToRestore, iconToRestore));
		creerUnFavoris(act, iconToRestore);
		controleFavVide();
	}


}

FenPrincipale::~FenPrincipale()
{
	QList<QVariant> urlListHis;
	QList<QVariant> urlTitleListHis;
	QList<QVariant> dateListHis;
	QList<QVariant> iconHis;

	QList<QVariant> urlListFav;
	QList<QVariant> urlTitleListFav;
	QList<QVariant> iconFav;

	ChainLine chainLineToSave;

	while(!m_hisBuffer->isVoid())
	{
		chainLineToSave = m_hisBuffer->popOutFirstIn();
		urlListHis.append(chainLineToSave.url());
		urlTitleListHis.append(chainLineToSave.action()->text());
		iconHis.append(chainLineToSave.action()->icon());
		dateListHis.append(chainLineToSave.date());
	}

	while(!m_favBuffer->isVoid())
	{
		chainLineToSave = m_favBuffer->popOutFirstIn();
		urlListFav.append(chainLineToSave.url());
		urlTitleListFav.append(chainLineToSave.action()->text());
		iconFav.append(chainLineToSave.action()->icon());
	}

	m_parametres->setValue("urlListHis", urlListHis);
	m_parametres->setValue("urlTitleListHis", urlTitleListHis);
	m_parametres->setValue("dateListHis", dateListHis);
	m_parametres->setValue("iconHis", iconHis);

	m_parametres->setValue("urlListFav", urlListFav);
	m_parametres->setValue("urlTitleListFav", urlTitleListFav);
	m_parametres->setValue("iconFav", iconFav);
	m_parametres->sync();
}
