#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include "Lager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    std::string getInputString() const;
    double getInputDouble() const;
    int getInputInt() const;
    QTextBrowser* getTextBrowser();
    QTextBrowser* getTextBrowser2();
    void dialog();
    void newLager();
    void getLager();
    void getDouble();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::string inputtext;
    int inputint;
    double inputdouble;
    Lager* lager;

private slots:


};

#endif // MAINWINDOW_H
