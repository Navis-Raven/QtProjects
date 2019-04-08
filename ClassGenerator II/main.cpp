#include <QApplication>
#include <QtWidgets>
#include "fencodegeneree.h"
#include "fenprincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);

    FenPrincipale fenetrePrincipale;

    fenetrePrincipale.show();

    //FenCodeGeneree fenetreGeneree;

    //fenetreGeneree.show();

    return app.exec();
}

