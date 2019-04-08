/********************************************************************************
** Form generated from reading UI file 'SearchDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *boutonPrec;
    QPushButton *boutonSuiv;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QString::fromUtf8("SearchDialog"));
        SearchDialog->resize(433, 132);
        SearchDialog->setModal(false);
        gridLayout = new QGridLayout(SearchDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        boutonPrec = new QPushButton(SearchDialog);
        boutonPrec->setObjectName(QString::fromUtf8("boutonPrec"));

        horizontalLayout->addWidget(boutonPrec);

        boutonSuiv = new QPushButton(SearchDialog);
        boutonSuiv->setObjectName(QString::fromUtf8("boutonSuiv"));

        horizontalLayout->addWidget(boutonSuiv);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        lineEdit = new QLineEdit(SearchDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        checkBox = new QCheckBox(SearchDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        QWidget::setTabOrder(lineEdit, checkBox);
        QWidget::setTabOrder(checkBox, boutonSuiv);
        QWidget::setTabOrder(boutonSuiv, boutonPrec);

        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QApplication::translate("SearchDialog", "Rechercher", nullptr));
        boutonPrec->setText(QApplication::translate("SearchDialog", "&Pr\303\251c\303\251dant", nullptr));
        boutonSuiv->setText(QApplication::translate("SearchDialog", "&Suivant", nullptr));
        checkBox->setText(QApplication::translate("SearchDialog", "&Respecter la casse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
