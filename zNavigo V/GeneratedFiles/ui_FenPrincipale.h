/********************************************************************************
** Form generated from reading UI file 'FenPrincipale.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENPRINCIPALE_H
#define UI_FENPRINCIPALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenPrincipaleClass
{
public:
    QAction *actionPage_suivante;
    QAction *actionPage_pr_c_dente;
    QAction *action_Actualiser;
    QAction *actionPage_d_a_cceuil;
    QAction *action_A_propos;
    QAction *actionA_porpos_de_Qt;
    QAction *actionNouvel_onglet;
    QAction *actiontest;
    QAction *action_Fermer;
    QAction *actionFermer_onglet;
    QAction *actionArr_ter_le_chargement;
    QAction *action_vide;
    QAction *action_Effacer_historique;
    QAction *action_vide_2;
    QAction *action_Ajouter_aux_favoris;
    QAction *action_Effacer_la_liste_des_favoris;
    QAction *action_Rechercher;
    QAction *action_Param_tres;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_Fichier;
    QMenu *menuNavigation;
    QMenu *menu_Historique;
    QMenu *menu_Favoris;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FenPrincipaleClass)
    {
        if (FenPrincipaleClass->objectName().isEmpty())
            FenPrincipaleClass->setObjectName(QString::fromUtf8("FenPrincipaleClass"));
        FenPrincipaleClass->resize(1303, 785);
        FenPrincipaleClass->setContextMenuPolicy(Qt::ActionsContextMenu);
        actionPage_suivante = new QAction(FenPrincipaleClass);
        actionPage_suivante->setObjectName(QString::fromUtf8("actionPage_suivante"));
        actionPage_pr_c_dente = new QAction(FenPrincipaleClass);
        actionPage_pr_c_dente->setObjectName(QString::fromUtf8("actionPage_pr_c_dente"));
        action_Actualiser = new QAction(FenPrincipaleClass);
        action_Actualiser->setObjectName(QString::fromUtf8("action_Actualiser"));
        actionPage_d_a_cceuil = new QAction(FenPrincipaleClass);
        actionPage_d_a_cceuil->setObjectName(QString::fromUtf8("actionPage_d_a_cceuil"));
        action_A_propos = new QAction(FenPrincipaleClass);
        action_A_propos->setObjectName(QString::fromUtf8("action_A_propos"));
        actionA_porpos_de_Qt = new QAction(FenPrincipaleClass);
        actionA_porpos_de_Qt->setObjectName(QString::fromUtf8("actionA_porpos_de_Qt"));
        actionNouvel_onglet = new QAction(FenPrincipaleClass);
        actionNouvel_onglet->setObjectName(QString::fromUtf8("actionNouvel_onglet"));
        actiontest = new QAction(FenPrincipaleClass);
        actiontest->setObjectName(QString::fromUtf8("actiontest"));
        action_Fermer = new QAction(FenPrincipaleClass);
        action_Fermer->setObjectName(QString::fromUtf8("action_Fermer"));
        actionFermer_onglet = new QAction(FenPrincipaleClass);
        actionFermer_onglet->setObjectName(QString::fromUtf8("actionFermer_onglet"));
        actionArr_ter_le_chargement = new QAction(FenPrincipaleClass);
        actionArr_ter_le_chargement->setObjectName(QString::fromUtf8("actionArr_ter_le_chargement"));
        action_vide = new QAction(FenPrincipaleClass);
        action_vide->setObjectName(QString::fromUtf8("action_vide"));
        action_vide->setEnabled(false);
        action_Effacer_historique = new QAction(FenPrincipaleClass);
        action_Effacer_historique->setObjectName(QString::fromUtf8("action_Effacer_historique"));
        action_vide_2 = new QAction(FenPrincipaleClass);
        action_vide_2->setObjectName(QString::fromUtf8("action_vide_2"));
        action_vide_2->setEnabled(false);
        action_Ajouter_aux_favoris = new QAction(FenPrincipaleClass);
        action_Ajouter_aux_favoris->setObjectName(QString::fromUtf8("action_Ajouter_aux_favoris"));
        action_Effacer_la_liste_des_favoris = new QAction(FenPrincipaleClass);
        action_Effacer_la_liste_des_favoris->setObjectName(QString::fromUtf8("action_Effacer_la_liste_des_favoris"));
        action_Rechercher = new QAction(FenPrincipaleClass);
        action_Rechercher->setObjectName(QString::fromUtf8("action_Rechercher"));
        action_Param_tres = new QAction(FenPrincipaleClass);
        action_Param_tres->setObjectName(QString::fromUtf8("action_Param_tres"));
        centralWidget = new QWidget(FenPrincipaleClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        FenPrincipaleClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FenPrincipaleClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1303, 26));
        menu_Fichier = new QMenu(menuBar);
        menu_Fichier->setObjectName(QString::fromUtf8("menu_Fichier"));
        menuNavigation = new QMenu(menuBar);
        menuNavigation->setObjectName(QString::fromUtf8("menuNavigation"));
        menu_Historique = new QMenu(menuNavigation);
        menu_Historique->setObjectName(QString::fromUtf8("menu_Historique"));
        menu_Favoris = new QMenu(menuNavigation);
        menu_Favoris->setObjectName(QString::fromUtf8("menu_Favoris"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        FenPrincipaleClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FenPrincipaleClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setContextMenuPolicy(Qt::NoContextMenu);
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(false);
        FenPrincipaleClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FenPrincipaleClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FenPrincipaleClass->setStatusBar(statusBar);

        menuBar->addAction(menu_Fichier->menuAction());
        menuBar->addAction(menuNavigation->menuAction());
        menuBar->addAction(menu->menuAction());
        menu_Fichier->addAction(actionNouvel_onglet);
        menu_Fichier->addAction(actionFermer_onglet);
        menu_Fichier->addAction(action_Param_tres);
        menu_Fichier->addSeparator();
        menu_Fichier->addAction(action_Fermer);
        menuNavigation->addAction(actionPage_suivante);
        menuNavigation->addAction(actionPage_pr_c_dente);
        menuNavigation->addAction(actionArr_ter_le_chargement);
        menuNavigation->addAction(action_Actualiser);
        menuNavigation->addAction(actionPage_d_a_cceuil);
        menuNavigation->addSeparator();
        menuNavigation->addAction(menu_Historique->menuAction());
        menuNavigation->addAction(menu_Favoris->menuAction());
        menuNavigation->addSeparator();
        menuNavigation->addAction(action_Rechercher);
        menu_Historique->addAction(action_Effacer_historique);
        menu_Historique->addSeparator();
        menu_Historique->addAction(action_vide);
        menu_Favoris->addAction(action_Ajouter_aux_favoris);
        menu_Favoris->addAction(action_Effacer_la_liste_des_favoris);
        menu_Favoris->addSeparator();
        menu_Favoris->addAction(action_vide_2);
        menu->addSeparator();
        menu->addAction(action_A_propos);
        menu->addAction(actionA_porpos_de_Qt);

        retranslateUi(FenPrincipaleClass);

        QMetaObject::connectSlotsByName(FenPrincipaleClass);
    } // setupUi

    void retranslateUi(QMainWindow *FenPrincipaleClass)
    {
        FenPrincipaleClass->setWindowTitle(QApplication::translate("FenPrincipaleClass", "FenPrincipale", nullptr));
        actionPage_suivante->setText(QApplication::translate("FenPrincipaleClass", "Page &suivante", nullptr));
        actionPage_pr_c_dente->setText(QApplication::translate("FenPrincipaleClass", "Page &pr\303\251c\303\251dente", nullptr));
        action_Actualiser->setText(QApplication::translate("FenPrincipaleClass", "&Actualiser", nullptr));
        actionPage_d_a_cceuil->setText(QApplication::translate("FenPrincipaleClass", "Page d'a&cceuil", nullptr));
        action_A_propos->setText(QApplication::translate("FenPrincipaleClass", "&A propos...", nullptr));
        actionA_porpos_de_Qt->setText(QApplication::translate("FenPrincipaleClass", "A porpos de &Qt...", nullptr));
        actionNouvel_onglet->setText(QApplication::translate("FenPrincipaleClass", "&Nouvel onglet", nullptr));
        actiontest->setText(QApplication::translate("FenPrincipaleClass", "test", nullptr));
        action_Fermer->setText(QApplication::translate("FenPrincipaleClass", "&Fermer", nullptr));
        actionFermer_onglet->setText(QApplication::translate("FenPrincipaleClass", "Fermer &onglet", nullptr));
        actionArr_ter_le_chargement->setText(QApplication::translate("FenPrincipaleClass", "Arr\303\252ter le chargement", nullptr));
        action_vide->setText(QApplication::translate("FenPrincipaleClass", "(vide)", nullptr));
        action_Effacer_historique->setText(QApplication::translate("FenPrincipaleClass", "&Effacer historique", nullptr));
        action_vide_2->setText(QApplication::translate("FenPrincipaleClass", "(vide)", nullptr));
        action_Ajouter_aux_favoris->setText(QApplication::translate("FenPrincipaleClass", "&Ajouter aux favoris", nullptr));
        action_Effacer_la_liste_des_favoris->setText(QApplication::translate("FenPrincipaleClass", "&Effacer la liste des favoris", nullptr));
        action_Rechercher->setText(QApplication::translate("FenPrincipaleClass", "&Rechercher", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Rechercher->setShortcut(QApplication::translate("FenPrincipaleClass", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        action_Param_tres->setText(QApplication::translate("FenPrincipaleClass", "&Param\303\250tres", nullptr));
        menu_Fichier->setTitle(QApplication::translate("FenPrincipaleClass", "&Fichier", nullptr));
        menuNavigation->setTitle(QApplication::translate("FenPrincipaleClass", "&Navigation", nullptr));
        menu_Historique->setTitle(QApplication::translate("FenPrincipaleClass", "&Historique", nullptr));
        menu_Favoris->setTitle(QApplication::translate("FenPrincipaleClass", "&Favoris", nullptr));
        menu->setTitle(QApplication::translate("FenPrincipaleClass", "&?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenPrincipaleClass: public Ui_FenPrincipaleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENPRINCIPALE_H
