#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <iostream>
#include <QTimer>

void update()
{
    std::cout<<"Update"<<std::endl;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);






}

Widget::~Widget()
{

    delete ui;
}



