#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Lagerdialog.h"
#include <QPushButton>
#include <QAction>
#include <QDir>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionBeenden, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionNeues_Lager, &QAction::triggered, this, &MainWindow::newLager);
    //connect(ui->actionLager_weiter_bearbeiten, &QAction::triggered, this, &MainWindow::dialog);
   // connect(ui->pushButton, SIGNAL (clicked()), this, SLOT (textInput()));
    this->getTextBrowser()->setText("Legen Sie ein neues Lager an: STRG + N \nLager weiter bearbeiten: STRG + W \nBeenden: STRG + B");
}

void MainWindow::dialog() {
//    if(this->lager == nullptr){
//        newLager();
//    }
    Lagerdialog* lagerdialog = nullptr;
    try {
            lagerdialog = new Lagerdialog(this->lager, this);
            if(lagerdialog->getLager() != nullptr){
            lagerdialog->start();
            delete lagerdialog;
            lagerdialog = nullptr;
            }
        } catch(exception& e) {
           this->getTextBrowser2()->setText(QString::fromStdString(e.what()));
    } catch(...) {
        this->getTextBrowser2()->setText(QString::fromStdString("Unbekannter Fehler beim Lagerdialog."));
    }
}

void MainWindow::newLager(){
    std::string name;
    getLager();
    int dim = 0;
    bool ok;
    name = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                 tr("Name des Lagers:"), QLineEdit::Normal,
                                 QDir::home().dirName(), &ok).toStdString();
    dim = QInputDialog::getInt(0, "Dimension", "Dimension des Lagers:", 1);
    try{
    Lager* lager = nullptr;
    lager = new Lager(name, dim);
    this->lager = lager;
    if(name != "" && dim > 0) {
        this->getTextBrowser()->setText("Lager wurde angelegt!");
    }
    } catch(exception& e) {
        this->getTextBrowser2()->setText(e.what());
    } catch(...){
        this->getTextBrowser2()->setText("Unbekannter Fehler beim Anlegen!");
    }

    this->inputint = dim;
    this->inputtext = name;
    if(this->lager != nullptr){
        connect(ui->actionLager_weiter_bearbeiten, &QAction::triggered, this, &MainWindow::dialog);
        dialog();
    }
}

void MainWindow::getLager(){
    QString qs = QString("Lager wird angelegt.");
    this->getTextBrowser()->setText(qs);
}

void MainWindow::getDouble(){

}


std::string MainWindow::getInputString() const {
    return this->inputtext;
}

QTextBrowser* MainWindow::getTextBrowser() {
    return ui->textBrowser;
}

QTextBrowser* MainWindow::getTextBrowser2() {
    return ui->textBrowser_2;
}

int MainWindow::getInputInt() const {
    return this->inputint;
}

double MainWindow::getInputDouble() const {
    return this->inputdouble;
}


MainWindow::~MainWindow()
{
    delete ui;
}
