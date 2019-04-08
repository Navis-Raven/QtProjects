#pragma once

#include <QtWebEngine>
#include <QtWebEngineWidgets>
#include <QtWidgets/QMainWindow>
#include "ui_FenPrincipale.h"
#include "ChainList.h"
#include "SearchDialog.h"
#include "FenParametres.h"

#define MAX_HIST	40
#define MAX_FAV		40

class FenPrincipale : public QMainWindow
{
	Q_OBJECT

	public:
		FenPrincipale(QWidget* parent = Q_NULLPTR);
		~FenPrincipale();
		QWebEngineView* pageActuelle();


	private:
		Ui::FenPrincipaleClass ui;

		enum FavActMode { ajouter, retirer, erreur_ajout };
		enum EffHistRet { fait, vide, annule };
	
		QWebEngineView* m_vuePrecedente;
		QLineEdit* m_barreAdresse;
		QAction* m_actionAllerA;
		QTabWidget* m_onglets;
		QPushButton* m_plusTab;
		QProgressBar* m_chargement;
		QStatusBar* m_statusBar;
		QString m_defaultFavTxt;
		int m_count_tabs;
		ChainList* m_hisBuffer;
		ChainList* m_favBuffer;
		QSettings* m_parametres;
		bool m_favActMode_ajouter;
		void changerFavActMode(FavActMode mode);
		void ajournerBarreAdresse();
		inline void controleFavVide();
		inline void controleFavActMode();
		void FenPrincipale::creerUnFavoris(QAction* act, QIcon const& icon);
		inline void configureView(QWebEngineView * view);
		void ajouterALHistorique(QString const& titre, QUrl const& url, QDate const& date, QIcon const& icon = QIcon());
		SearchDialog* m_fenetreChercher;
		FenParametres* m_fenParametres;
		inline void restaurerHisFav();

	private slots:
		void on_action_Actualiser_triggered();
		void on_actionPage_d_a_cceuil_triggered();
		void on_action_Fermer_triggered();
		void on_action_A_propos_triggered();
		void on_actionA_porpos_de_Qt_triggered();
		void on_action_Rechercher_triggered();
		void on_action_Param_tres_triggered();
		void occurencePrecedente();
		void occurenceSuivante();
		void on_actionNouvel_onglet_triggered();
		void titrerLOnglet(bool etat_OK);
		void iconerLOnglet(const QIcon & icon);
		void on_action_Effacer_la_liste_des_favoris_triggered();
		void on_actionFermer_onglet_triggered();
		void on_actionPage_pr_c_dente_triggered();
		void on_actionPage_suivante_triggered();
		void on_actionArr_ter_le_chargement_triggered();
		void resetChercher();
		void allerA();
		void ongletChange();
		void fermeLOnglet(int index);
		void chargementCommence();
		void chargementTermine();
		void on_action_Ajouter_aux_favoris_triggered();
		void effacerUnFavori();
		EffHistRet on_action_Effacer_historique_triggered();
		void gererSignalHistoriqueDesactive();
		void chargerHistorique();
		void chargerFavori();
		void sauverNouveauxParametres();

};




