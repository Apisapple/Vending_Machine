#include "widget.h"
#include "ui_widget.h"
#include "qstring.h"
#include "qmessagebox.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->PbTea->setEnabled(false);
    ui->PbCoffee->setEnabled(false);
    ui->PbCoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int num){

    ui->lcdNumber->display(QString::number(money+=num));
 //   ui->PbCoffee->setEnabled(false);
 //   QMessageBox msg;
 //   msg.information(nullptr,"title","text");
}
void Widget::checkMoney(){
    if(money >= 100){
        ui->PbCoffee->setEnabled(true);
    }
    if(money >= 150){
        ui->PbTea->setEnabled(true);
    }
    if(money >= 200){
        ui->PbCoke->setEnabled(true);
    }
    if(money < 200){
        ui->PbCoke->setEnabled(false);
    }
    if(money < 150){
        ui->PbTea->setEnabled(false);
    }
    if(money < 100){
        ui->PbCoffee->setEnabled(false);
    }
}
void Widget::on_Pb10_clicked()
{
    changeMoney(10);
    checkMoney();
}

void Widget::on_Pb50_clicked()
{
    changeMoney(50);
    checkMoney();
}

void Widget::on_Pb100_clicked()
{
   changeMoney(100);
   checkMoney();
}

void Widget::on_Pb500_clicked()
{
   changeMoney(500);
   checkMoney();
}

void Widget::on_PbCoffee_clicked()
{
    checkMoney();
    if(money>=100){
        changeMoney(-100);
        checkMoney();
    }
}

void Widget::on_PbTea_clicked()
{
    checkMoney();
    if(money>=150){
        changeMoney(-150);
        checkMoney();
    }
}

void Widget::on_PbCoke_clicked()
{
    checkMoney();
    if(money>=200){
        changeMoney(-200);
        checkMoney();
    }
}

void Widget::on_Pbret_clicked()
{
    int fiveHundred = 0;
    int Hundred = 0;
    int ten = 0;
    int fifty = 0;
    fiveHundred = money / 500;
    money %= 500;
    Hundred = money / 100;
    money %= 100;
    fifty = money / 50;
    money %= 50;
    ten = money / 10;
    QMessageBox msg;
    QString value = "500 :" + QString::number(fiveHundred) + " 100 :" + QString::number(Hundred) +" 50 :" + QString::number(fifty)+" 10 :" +QString::number(ten);
    msg.information(nullptr,"Return",value);
    changeMoney(-(money));
    checkMoney();
}
