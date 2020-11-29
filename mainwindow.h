#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void pencilWidth();
    void open();
    void saveWork();
    void pencilColor();

private:
    Ui::MainWindow *ui;
    void createAcions();
    void createMenus();
    bool isSaved = false;
    bool saveBoard(const QByteArray &board);
    QMenu *saveAs;

private:
    // variable for custom classes
     board *whiteBoard;

};
#endif // MAINWINDOW_H
