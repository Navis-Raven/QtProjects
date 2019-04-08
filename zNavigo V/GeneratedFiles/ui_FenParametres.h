/********************************************************************************
** Form generated from reading UI file 'FenParametres.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENPARAMETRES_H
#define UI_FENPARAMETRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FenParametres
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *pageDAccueuilLabel;
    QLineEdit *pageDAccueuilLineEdit;
    QPushButton *pageDAccueilActuelleBout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QCheckBox *activerHistoriqueChkBox;
    QPushButton *effacerHistoriqueBout;
    QPushButton *effacerFavorisBout;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *dialogBuBox;

    void setupUi(QDialog *FenParametres)
    {
        if (FenParametres->objectName().isEmpty())
            FenParametres->setObjectName(QString::fromUtf8("FenParametres"));
        FenParametres->resize(614, 181);
        FenParametres->setModal(true);
        verticalLayout = new QVBoxLayout(FenParametres);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        pageDAccueuilLabel = new QLabel(FenParametres);
        pageDAccueuilLabel->setObjectName(QString::fromUtf8("pageDAccueuilLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pageDAccueuilLabel);

        pageDAccueuilLineEdit = new QLineEdit(FenParametres);
        pageDAccueuilLineEdit->setObjectName(QString::fromUtf8("pageDAccueuilLineEdit"));
        pageDAccueuilLineEdit->setMinimumSize(QSize(450, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, pageDAccueuilLineEdit);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, formLayout);

        pageDAccueilActuelleBout = new QPushButton(FenParametres);
        pageDAccueilActuelleBout->setObjectName(QString::fromUtf8("pageDAccueilActuelleBout"));
        pageDAccueilActuelleBout->setMaximumSize(QSize(30, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("Wingdings 3"));
        font.setPointSize(10);
        pageDAccueilActuelleBout->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pageDAccueilActuelleBout);


        verticalLayout->addLayout(formLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        activerHistoriqueChkBox = new QCheckBox(FenParametres);
        activerHistoriqueChkBox->setObjectName(QString::fromUtf8("activerHistoriqueChkBox"));
        activerHistoriqueChkBox->setMaximumSize(QSize(150, 16777215));
        activerHistoriqueChkBox->setChecked(true);

        horizontalLayout->addWidget(activerHistoriqueChkBox);

        effacerHistoriqueBout = new QPushButton(FenParametres);
        effacerHistoriqueBout->setObjectName(QString::fromUtf8("effacerHistoriqueBout"));
        effacerHistoriqueBout->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(effacerHistoriqueBout);

        effacerFavorisBout = new QPushButton(FenParametres);
        effacerFavorisBout->setObjectName(QString::fromUtf8("effacerFavorisBout"));
        effacerFavorisBout->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(effacerFavorisBout);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        dialogBuBox = new QDialogButtonBox(FenParametres);
        dialogBuBox->setObjectName(QString::fromUtf8("dialogBuBox"));
        dialogBuBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(dialogBuBox);

#ifndef QT_NO_SHORTCUT
        pageDAccueuilLabel->setBuddy(pageDAccueuilLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(FenParametres);

        QMetaObject::connectSlotsByName(FenParametres);
    } // setupUi

    void retranslateUi(QDialog *FenParametres)
    {
        FenParametres->setWindowTitle(QApplication::translate("FenParametres", "Param\303\250tres", nullptr));
        pageDAccueuilLabel->setText(QApplication::translate("FenParametres", "&Page d'Accueuil:", nullptr));
        pageDAccueilActuelleBout->setText(QApplication::translate("FenParametres", "&L", nullptr));
        activerHistoriqueChkBox->setText(QApplication::translate("FenParametres", "&Activer historique", nullptr));
        effacerHistoriqueBout->setText(QApplication::translate("FenParametres", "Effacer &historique", nullptr));
        effacerFavorisBout->setText(QApplication::translate("FenParametres", "Effacer &favoris", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenParametres: public Ui_FenParametres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENPARAMETRES_H
