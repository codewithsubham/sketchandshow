#ifndef BOARD_H
#define BOARD_H

#include <QObject>

#include <QColor>
#include <QMouseEvent>
#include <QImage>
#include <QWidget>
class board : public QWidget
{
    Q_OBJECT
private:
    bool isSaved = false;
    QColor pencilColor;
    int Pencilwidth;
    bool drawing = false;
    QImage image;
    QPoint lastPoint;



public:
    explicit board(QObject *parent = nullptr);
    bool OpenImage(const QString &imagepath);
    bool saveImage(const QString &filename , const char &fileExtension);
    bool setPencilColor(const QColor &newColor);
    bool setPencilWidth(float width);
    bool isBoardChange() const {return isSaved;};

public:
   // getter functions;

    QColor getPenilColor() const {return  pencilColor;}
    int getPencilWidth() const {return  Pencilwidth;}

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void releaseMouse(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);


private:
    void drawLineTo(const QPoint &endPoint);
    void ResizeImage(QImage *image , const QSize &size);


signals:

};

#endif // BOARD_H
