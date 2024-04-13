#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE



#define MONEY_CNT 4
const uint32_t g_MONEY[MONEY_CNT] = {10, 50, 100, 500};

enum PRICE {
    COFFEE = 100,
    TEA = 150,
    MILK = 200
};

class Widget : public QWidget
{

    #define BTN_CLICKED_DEF(name) void on_##name##_clicked()
    #define BTN_CLICKED_DEF_WIDGET(name) void Widget::on_##name##_clicked()
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void update_money_panel();
    void buy(enum PRICE);
    uint32_t get_current_money();

private slots:
    BTN_CLICKED_DEF(btn_10);

    BTN_CLICKED_DEF(btn_50);

    BTN_CLICKED_DEF(btn_500);

    BTN_CLICKED_DEF(btn_100);

    BTN_CLICKED_DEF(btn_coffee);

    BTN_CLICKED_DEF(btn_milk);

    BTN_CLICKED_DEF(btn_reset);

    BTN_CLICKED_DEF(btn_tea);

private:
    Ui::Widget *ui;
    uint32_t money = 0;


};
#endif // WIDGET_H
