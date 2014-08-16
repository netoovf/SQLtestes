#ifndef SQLTEST_H
#define SQLTEST_H

#include <QDialog>
#include <QSqlQueryModel>


namespace Ui {
class sqltest;
}

class sqltest : public QDialog
{
    Q_OBJECT
    
public slots:
    void connect();
    void desconnect();
public:
    explicit sqltest(QWidget *parent = 0);
    ~sqltest();

private:
    Ui::sqltest *ui;
    QSqlQueryModel *txt_query;
    void habilitarQuery(bool ativo);
    void valoresIniciais();
};

#endif // SQLTEST_H
