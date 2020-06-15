#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRubberBand>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QPoint origin;
    QRubberBand *select;
    QPixmap fragment;
    QString initialPath;
    QScreen* screen;
    QString filename;
    QString text_to_copy;
    int x_press;
    int y_press;
    int x_release;
    int y_release;
    int width;
    int height;




    ~MainWindow();
private slots:

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *eventREL);
    void on_SelectText_clicked();
    void DeleteFile();
    void Back();
    void Tesseract();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
