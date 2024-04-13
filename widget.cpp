#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    money = 0;
    update_money_panel();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::update_money_panel() {
    ui->currnet_money_lcd->display((double)money);

    ui->btn_coffee->setDisabled(true);
    ui->btn_tea->setDisabled(true);
    ui->btn_milk->setDisabled(true);

    if(money < COFFEE) {
        // no action
    } else if (money < TEA) {
        ui->btn_coffee->setDisabled(false);

    } else if (money < MILK){
        ui->btn_coffee->setDisabled(false);
        ui->btn_tea->setDisabled(false);

    } else {
        ui->btn_coffee->setDisabled(false);
        ui->btn_tea->setDisabled(false);
        ui->btn_milk->setDisabled(false);
    }
}

void Widget::buy(enum PRICE p) {
    uint32_t price = (uint32_t)p;
    if(money >= price)
        money -= price;

    update_money_panel();
}


BTN_CLICKED_DEF_WIDGET(btn_10) {
    money += 10;
    update_money_panel();
}


BTN_CLICKED_DEF_WIDGET(btn_50) {
    money += 50;
    update_money_panel();
}


BTN_CLICKED_DEF_WIDGET(btn_100) {
    money += 100;
    update_money_panel();
}


BTN_CLICKED_DEF_WIDGET(btn_500) {
    money += 500;
    update_money_panel();
}


BTN_CLICKED_DEF_WIDGET(btn_coffee) {
    buy(COFFEE);
}


BTN_CLICKED_DEF_WIDGET(btn_tea) {
    buy(TEA);
}


BTN_CLICKED_DEF_WIDGET(btn_milk) {
    buy(MILK);
}


BTN_CLICKED_DEF_WIDGET(btn_reset) {
    char result[0x1000] = {0, };
    char tmp[0x1000] = {0, };
    char remainder[MONEY_CNT] = {0,};
    uint32_t q;

    for(int i = MONEY_CNT - 1; i >= 0 && money > 0; i--) {
        q = money / g_MONEY[i];
        if(q == 0) continue;
        money -= g_MONEY[i] * q;

        strncpy(tmp, result, sizeof(tmp));
        snprintf(result, sizeof(result), "%s%d = %d ", tmp,  g_MONEY[i], q);
    }


    QMessageBox::question(this, "Vendor Machine", result, QMessageBox::Yes);
    update_money_panel();
}


