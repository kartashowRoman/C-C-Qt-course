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
    int x_press;
    int y_press;
    int x_release;
    int y_release;
    int width;
    int height;



    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *eventREL);


    void on_pushButton_2_clicked();

    void on_pushButton_2_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
