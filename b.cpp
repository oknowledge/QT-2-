#include "b.h"
#include "ui_b.h"
#include <QIcon>
#include "smart.h"
b::b(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::b)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/smart.png"));

    // 连接数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
    } else {
        createUsersTable();
    }
}

b::~b()
{
    delete ui;
    db.close();
}

void b::createUsersTable()
{
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "username TEXT NOT NULL UNIQUE, "
                    "password TEXT NOT NULL)")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void b::on_btnLogin_clicked()
{
    QString username = ui->textUser->text();
    QString password = ui->password->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (query.exec() && query.next()) {
        accept();
        this->close();
        // 这里可以打开新的界面
        accept();
        this->close();
        smart *pic=new smart();
        pic->show();
    } else {
        // 修正后的调用语句
        QMessageBox::warning(this, tr("Warning"), tr("UserName or Password Error!"), QMessageBox::Yes);
    }
}

void b::on_btnCreateAccount_clicked()
{
    QString username = ui->textUser->text();
    QString password = ui->password->text();

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Account created successfully!");
    } else {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void b::on_btnDeleteAccount_clicked()
{
    QString username = ui->textUser->text();
    QString password = ui->password->text();

    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (query.exec() && query.numRowsAffected() > 0) {
        QMessageBox::information(this, "Success", "Account deleted successfully!");

    } else {
        QMessageBox::critical(this, "Error", "Failed to delete account or account not found.");
    }
}
