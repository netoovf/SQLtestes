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
void sqltest::conectar()
{
QSqlDatabase db = QSqlDatabase::addDatabase("SQLLITE");
    db.setDatabaseName(ui->edt_schema->text().trimmed());

    if (!db.open())
    {
        QMessageBox::critical(this, "Falha",
                              "Falha na conexão com o BD [" + ui->edt_schema->text() + "]\n" + db.lastError().text(),
                              QMessageBox::Cancel);
        return;
    }

    QSqlQuery qry;
    qry.prepare("SELECT datetime('now')");
    if (!qry.exec()){
        QString erro = qry.lastError().text();
        QMessageBox::critical(this, "Falha",
                              "Falha ao preparar consulta do BD" + erro + "\n",
                              QMessageBox::Cancel);
    }
    else if (qry.next())
        QMessageBox::information(this, "Banco Tutorial",
                                 "Conexão realizada com sucesso com o Banco ["
                                 + ui->edt_schema->text() + "]\n[" + qry.value(0).toDateTime().toString() + "]" ,
                                 QMessageBox::Ok);

    habilitar_query(true);
    ui->txt_sql->setFocus();
}
}
void sqltest::desconectar()
{
QSqlDatabase db = QSqlDatabase::database();
    db.close();

    habilitar_query(false);
    ui->edt_schema->setFocus();
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
    ui->edt_schema->setDisabled(ativo);
}
