#ifndef B_H
#define B_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class b; }
QT_END_NAMESPACE

class b : public QDialog
{
    Q_OBJECT

public:
    b(QWidget *parent = nullptr);
    ~b();

private slots:
    void on_btnLogin_clicked();
    void on_btnCreateAccount_clicked();
    void on_btnDeleteAccount_clicked();

private:
    Ui::b *ui;
    QSqlDatabase db;
    void createUsersTable();
};
#endif // B_H
