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
    habilitarQuery(false);
     connect (ui->Connecbutt, SIGNAL(clicked()),this, SLOT(conectar()));
    connect (ui->descbutt, SIGNAL(clicked()),this, SLOT(desconectar()));
    connect (ui->Exebutt, SIGNAL(clicked()),this, SLOT(exeSqL()));
            ui->lineEdit_2->setFocus();
            txt_query = new QSqlQueryModel;

}
sqltest::~sqltest()
{
    delete ui;
}
void sqltest::Validarcampos()
{
    if(ui->lineEdit_2->text().trimmed().isEmpty())
        QMessageBox::critical(this, "Deus Bosta", "Digite o nome do BD:")
        ui->lineEdit_2->setFocus();
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
        ui->descbutt->setEnabled(ativo);
    ui->Exebutt->setEnabled(ativo);
    ui->plainTextEdit->setEnabled(ativo);

    ui->plainTextEdit->setDesabled(ativo);
}
