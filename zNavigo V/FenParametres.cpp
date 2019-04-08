#include "FenParametres.h"

FenParametres::FenParametres(QString const& pageDAccueil, bool historiqueActive, QWidget *parent): QDialog(parent), m_pageDAccueil(pageDAccueil), m_historiqueActive(historiqueActive)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint); //retirer le '?'
	setFixedSize(615, 180);

	resetParam();

	connect(ui.activerHistoriqueChkBox, SIGNAL(toggled(bool)), this, SLOT(slotHistoriqueChkBox(bool)));

	connect(this, SIGNAL(finished(int)), this, SLOT(resetParam()));
	connect(ui.dialogBuBox, SIGNAL(accepted()), this, SLOT(slotOK()));
	connect(ui.dialogBuBox, SIGNAL(rejected()), this, SLOT(slotAnnuler()));
}

FenParametres::~FenParametres()
{
}

void FenParametres::on_pageDAccueilActuelleBout_clicked()
{
	ui.pageDAccueuilLineEdit->setText(m_pageDAccueil);
}

void FenParametres::setPageDAccueil(const QString& pageDAccueil)
{
	m_pageDAccueil = pageDAccueil;
	on_pageDAccueilActuelleBout_clicked();
}

QString FenParametres::pageDAccueil() const
{
	return m_pageDAccueil;
}

void FenParametres::setActiverHistorique(bool on_off)
{
	m_historiqueActive = on_off;
	ui.activerHistoriqueChkBox->setChecked(m_historiqueActive);
}

bool FenParametres::etatActiverHistorique() const
{
	return m_historiqueActive;
}

void FenParametres::on_effacerFavorisBout_clicked()
{
	emit effacerFavSingal();
}

void FenParametres::on_effacerHistoriqueBout_clicked()
{
	emit effacerHistSignal();
}

void FenParametres::resetParam()
{
	on_pageDAccueilActuelleBout_clicked();
	ui.activerHistoriqueChkBox->setChecked(m_historiqueActive);
}

void FenParametres::slotOK()
{
	m_pageDAccueil = ui.pageDAccueuilLineEdit->text();
	m_historiqueActive = ui.activerHistoriqueChkBox->isChecked();
	close();
	emit nouveauxParametres();
}

void FenParametres::slotAnnuler()
{
	resetParam();
	close();
}


void FenParametres::slotHistoriqueChkBox(bool etat)
{
	if(etat == false)
	{
		ui.effacerHistoriqueBout->setEnabled(false);
		ui.effacerHistoriqueBout->isEnabled();
		emit historiqueDesactive();
	}
	else
	{
		ui.effacerHistoriqueBout->setEnabled(true);
		ui.effacerHistoriqueBout->isEnabled();
	}
}
