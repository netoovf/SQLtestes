#include "sqltest.h"

#include <QtWidgets>

int main (int argc, char *argv[])
{
    QApplication app (argc, argv);


    sqltest form;
    form.show();

    return app.exec();


}
