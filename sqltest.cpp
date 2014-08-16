#include "sqltest.h"
#include "ui_sqltest.h"

#include <QMessageBox>
#include <QtGui>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>


sqltest::sqltest(QWidget *parent):
    QDialog(parent),
    ui(new Ui::sqltest)
{
    ui->setupUi(this);
    this->setWindowTitle("SQL TESTE");
    habilitarQuer(false);
}
sqltest::~sqltest()
{
    delete ui;
}

void sqltest::connect()
{

}
void sqltest::desconnect()
{

}
void sqltest::exeSQL()
{

}
void sqltest::habilitarQuery(bool ativo)
{

}
