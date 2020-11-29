#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"
#include "QFileDialog"
#include "QString"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    whiteBoard = new board(this);
    setCentralWidget(whiteBoard);
    createAcions();
    createMenus();
    setWindowTitle("skethandshow");

}

void MainWindow::closeEvent(QCloseEvent *event){
    if(isSaved){
        event->accept();
        return;
    }
    event->ignore();
    return;
}



void MainWindow::open(){
    if(isSaved){
        QString fileName = QFileDialog::getOpenFileName(this , tr("open file") , QDir::currentPath());
        if(!fileName){
            whiteBoard->OpenImage(fileName);
        }
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}

