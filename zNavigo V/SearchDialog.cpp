#include "SearchDialog.h"

SearchDialog::SearchDialog(QWidget* parent) : QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint); //retirer le '?'
	setFixedSize(300, 125);
	ui.lineEdit->setText("");
	connect(ui.lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(slotTextChange()));
}

SearchDialog::~SearchDialog()
{
}

void SearchDialog::setTexteAChercher(const QString& texte)
{
	//ui.lineEdit->blockSignals(true);
	ui.lineEdit->setText(texte);
	//ui.lineEdit->blockSignals(false);
}

QString SearchDialog::texteAChercher() const
{
	return ui.lineEdit->text();
}

bool SearchDialog::repecterLaCasse() const
{
	return ui.checkBox->isChecked();
}


void SearchDialog::on_boutonPrec_clicked()
{
	emit boutonPrecSignal();
}

void SearchDialog::on_boutonSuiv_clicked()
{
	emit boutonSuivSignal();
}

void SearchDialog::slotTextChange()
{
	emit signalTextChange();
}


