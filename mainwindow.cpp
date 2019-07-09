#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "string"

using namespace std;

void cleanAll();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeAn_clicked()
{

}

QString temp2 ;
char  num1[50]={0};  //第一个操作数数组(最高支持4位)
char  num2[50]={0};  //第二个操作数数组(最高支持4位)
int   num3,num4;     //操作数转化int(最高支持4位)
int   flag=0;             //切换操作数数组标志
int pos1 = 0;
int pos2 = 0;
int oper = 0;

void MainWindow::slot1()  // 数字获取
{
    QPushButton *bt = (QPushButton *)sender();
    QString temp = bt->text();
    temp2 = ui->lineEdit->text();
    temp2 += temp;

    //show
    ui->lineEdit->setText(temp2);

    //test
    cout << bt->text().toStdString() << endl;

    if(flag==0)
    {
        num1[pos1] = bt->text().toStdString()[0];
        pos1++;
    }else{
        num2[pos2] = bt->text().toStdString()[0];
        pos2++;
    }

}

void MainWindow::on_deng_clicked()  // 等于
{
    int result = 0;

    QPushButton *bt = (QPushButton *)sender();
    QString temp = bt->text();
    temp2 = ui->lineEdit->text();
    temp2 += temp;

    //show =
    ui->lineEdit->setText(temp2);

    // oper
    num3=atoi(num1);  //char数组截断转化为int
    num4=atoi(num2);

    switch(oper)
    {
    case 1: // +
        result = num3 + num4;
        break;

    case 2: // -
        result = num3 - num4;
        break;

    case 3: // ×
        result = num3 * num4;
        break;

    case 4: // ÷
        result = num3 / num4;
        break;
    }

    cout << result << endl; // test

    temp = QString::number(result);
    temp2 = ui->lineEdit->text();
    temp2 += temp;

    //show result
    ui->lineEdit->setText(temp2);

    // clean
    cleanAll();

}

void MainWindow::on_jia_clicked()   // +
{

    QPushButton *bt = (QPushButton *)sender();
    QString temp = bt->text();
    temp2 = ui->lineEdit->text();
    temp2 += temp;

    //show
    ui->lineEdit->setText(temp2);

    oper =1;
    flag = 1;
}

void MainWindow::on_jian_clicked()  // -
{
    QPushButton *bt = (QPushButton *)sender();
    QString temp = bt->text();
    temp2 = ui->lineEdit->text();
    temp2 += temp;

    //show
    ui->lineEdit->setText(temp2);

    oper = 2;
    flag = 1;
}

void MainWindow::on_cheng_clicked() // ×
{
    QPushButton *bt = (QPushButton *)sender();
    QString temp = bt->text();
    temp2 = ui->lineEdit->text();
    temp2 += temp;

    //show
    ui->lineEdit->setText(temp2);

    oper = 3;
    flag = 1;
}


void MainWindow::on_chu_clicked()  // ÷
{
    QPushButton *bt = (QPushButton *)sender();
    QString temp = bt->text();
    temp2 = ui->lineEdit->text();
    temp2 += temp;

    //show
    ui->lineEdit->setText(temp2);

    oper = 4;
    flag = 1;
}

void cleanAll()
{
    flag=0;             //切换操作数数组标志
    pos1 = 0;
    pos2 = 0;
    oper = 0;

    for(int k=0;k<4;k++)
    {
        num1[k]='\0';
        num2[k]='\0';
    }
}

void MainWindow::on_cleanAll_clicked()
{

    //show
    ui->lineEdit->clear();

    // clean
    cleanAll();
}
