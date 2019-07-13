#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int num);
    void checkMoney();
    int money{0};
private slots:
     void on_Pb10_clicked();

     void on_Pb50_clicked();

     void on_Pb100_clicked();

     void on_Pb500_clicked();

     void on_PbCoffee_clicked();

     void on_PbTea_clicked();

     void on_PbCoke_clicked();



     void on_Pbret_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
