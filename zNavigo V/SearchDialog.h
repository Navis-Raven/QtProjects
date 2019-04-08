#pragma once

#include <QDialog>
#include "ui_SearchDialog.h"


class SearchDialog : public QDialog
{
	Q_OBJECT

public:
	SearchDialog(QWidget *parent = Q_NULLPTR);
	~SearchDialog();
	void setTexteAChercher(const QString& texte);
	QString texteAChercher() const;
	bool repecterLaCasse() const;

signals:
	void boutonPrecSignal();
	void boutonSuivSignal();
	void signalTextChange();

private slots:
	void on_boutonPrec_clicked();
	void on_boutonSuiv_clicked();
	void slotTextChange();

private:
	Ui::SearchDialog ui;

};

