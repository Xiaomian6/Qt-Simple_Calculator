#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_closeAn_clicked();

    void on_deng_clicked();

    void on_jia_clicked();

    void on_jian_clicked();

    void on_cheng_clicked();

    void on_chu_clicked();

    void on_cleanAll_clicked();

private:
    Ui::MainWindow *ui;

public slots:
    void slot1();
};


#endif // MAINWINDOW_H
