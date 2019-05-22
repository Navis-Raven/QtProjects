/********************************************************************************
** Form generated from reading UI file 'FenClient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENCLIENT_H
#define UI_FENCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenClientClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *serveurIP;
    QLabel *label_2;
    QSpinBox *serveurPort;
    QLabel *labelPseudo;
    QLineEdit *pseudo;
    QPushButton *boutonConnexion;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *listeMessages;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QListView *listViewConnectes;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelMessage;
    QLineEdit *message;
    QPushButton *boutonEnvoyer;

    void setupUi(QWidget *FenClientClass)
    {
        if (FenClientClass->objectName().isEmpty())
            FenClientClass->setObjectName(QString::fromUtf8("FenClientClass"));
        FenClientClass->resize(860, 600);
        FenClientClass->setMinimumSize(QSize(860, 600));
        FenClientClass->setMaximumSize(QSize(860, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        FenClientClass->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        FenClientClass->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(FenClientClass);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FenClientClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        serveurIP = new QLineEdit(FenClientClass);
        serveurIP->setObjectName(QString::fromUtf8("serveurIP"));
        serveurIP->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(serveurIP);

        label_2 = new QLabel(FenClientClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        serveurPort = new QSpinBox(FenClientClass);
        serveurPort->setObjectName(QString::fromUtf8("serveurPort"));
        serveurPort->setMinimumSize(QSize(60, 0));
        serveurPort->setMinimum(1024);
        serveurPort->setMaximum(65535);
        serveurPort->setValue(50885);

        horizontalLayout->addWidget(serveurPort);

        labelPseudo = new QLabel(FenClientClass);
        labelPseudo->setObjectName(QString::fromUtf8("labelPseudo"));

        horizontalLayout->addWidget(labelPseudo);

        pseudo = new QLineEdit(FenClientClass);
        pseudo->setObjectName(QString::fromUtf8("pseudo"));
        pseudo->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(pseudo);

        boutonConnexion = new QPushButton(FenClientClass);
        boutonConnexion->setObjectName(QString::fromUtf8("boutonConnexion"));

        horizontalLayout->addWidget(boutonConnexion);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(FenClientClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8("chat.png")));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(FenClientClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listeMessages = new QTextEdit(FenClientClass);
        listeMessages->setObjectName(QString::fromUtf8("listeMessages"));
        listeMessages->setMinimumSize(QSize(650, 0));
        listeMessages->setReadOnly(true);

        horizontalLayout_3->addWidget(listeMessages);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(FenClientClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        listViewConnectes = new QListView(FenClientClass);
        listViewConnectes->setObjectName(QString::fromUtf8("listViewConnectes"));
        listViewConnectes->setEnabled(false);
        listViewConnectes->setMaximumSize(QSize(175, 16777215));

        verticalLayout_3->addWidget(listViewConnectes);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelMessage = new QLabel(FenClientClass);
        labelMessage->setObjectName(QString::fromUtf8("labelMessage"));

        horizontalLayout_2->addWidget(labelMessage);

        message = new QLineEdit(FenClientClass);
        message->setObjectName(QString::fromUtf8("message"));

        horizontalLayout_2->addWidget(message);

        boutonEnvoyer = new QPushButton(FenClientClass);
        boutonEnvoyer->setObjectName(QString::fromUtf8("boutonEnvoyer"));
        boutonEnvoyer->setIcon(icon);

        horizontalLayout_2->addWidget(boutonEnvoyer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(pseudo, boutonConnexion);
        QWidget::setTabOrder(boutonConnexion, serveurIP);
        QWidget::setTabOrder(serveurIP, serveurPort);
        QWidget::setTabOrder(serveurPort, message);
        QWidget::setTabOrder(message, boutonEnvoyer);

        retranslateUi(FenClientClass);

        QMetaObject::connectSlotsByName(FenClientClass);
    } // setupUi

    void retranslateUi(QWidget *FenClientClass)
    {
        FenClientClass->setWindowTitle(QApplication::translate("FenClientClass", "ZeroChat", nullptr));
        label->setText(QApplication::translate("FenClientClass", "IP du serveur :", nullptr));
        serveurIP->setText(QApplication::translate("FenClientClass", "127.0.0.1", nullptr));
        label_2->setText(QApplication::translate("FenClientClass", "Port du serveur :", nullptr));
        labelPseudo->setText(QApplication::translate("FenClientClass", "Pseudo :", nullptr));
        boutonConnexion->setText(QApplication::translate("FenClientClass", "&Connexion", nullptr));
        label_6->setText(QApplication::translate("FenClientClass", "ZeroChat", nullptr));
        label_3->setText(QApplication::translate("FenClientClass", "Personnes connect\303\251es:", nullptr));
        labelMessage->setText(QApplication::translate("FenClientClass", "Message :", nullptr));
        boutonEnvoyer->setText(QApplication::translate("FenClientClass", "&Envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenClientClass: public Ui_FenClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENCLIENT_H
