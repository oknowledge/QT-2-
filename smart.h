#ifndef SMART_H
#define SMART_H

#include <QWidget>
#include <QMovie>
#include "textscroll.h"
#include "SQL.h"
QT_BEGIN_NAMESPACE
namespace Ui { class smart; }
QT_END_NAMESPACE

class smart : public QWidget
{
    Q_OBJECT

public:
    smart(QWidget *parent = nullptr);
    ~smart();

private slots:
    void on_pushButton_clicked();
    void on_pb1_clicked();
    void on_lan1_clicked();
    void on_lan2_clicked();
    void on_lan3_clicked();

    void onBtnPage1();
    void onBtnPage2();
    void onBtnPage3();
    void onBtnPage4();
    void onBtnPage5();
    void onBtnPage6();
    void onBtnPage7();
    void onBtnPage8();
    void onBtnPage9();
    void fanmove();void kongmove();
    void on_fan_clicked(int param);
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
private:
    Ui::smart *ui;
    QMovie *fanMovie;
    QMovie *kong;
    bool flag8;
    int i=25;
    int modeIndex = 0,modeIndex1=0,modeIndex2 = 0,modeIndex3=0;
};
#endif // SMART_H
