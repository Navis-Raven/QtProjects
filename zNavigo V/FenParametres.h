#pragma once

#include <QDialog>
#include "ui_FenParametres.h"

class FenParametres : public QDialog
{
	Q_OBJECT

	public:
		FenParametres(QString const& pageDAccueil, bool historiqueActive, QWidget *parent = Q_NULLPTR);
		~FenParametres();
		void setPageDAccueil(const QString& pageDAccueil);
		QString pageDAccueil() const;
		void setActiverHistorique(bool on_off);
		bool etatActiverHistorique() const;
	
	private:
		Ui::FenParametres ui;
		QString m_pageDAccueil;
		bool m_historiqueActive;

	private slots:
		void on_effacerFavorisBout_clicked();
		void on_effacerHistoriqueBout_clicked();
		void on_pageDAccueilActuelleBout_clicked();
		void resetParam();
		void slotOK();
		void slotAnnuler();
		void slotHistoriqueChkBox(bool etat);

	signals:
		void effacerFavSingal();
		void effacerHistSignal();
		void historiqueDesactive();
		void nouveauxParametres();

};
