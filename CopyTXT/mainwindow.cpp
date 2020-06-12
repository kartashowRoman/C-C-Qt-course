#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QWindow>
#include <QScreen>
#include <QString>
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include <QDir>
#include <QStandardPaths>
#include <QFileDialog>
#include <QImageWriter>
#include <QMessageBox>
#include <QTextEdit>
#include <QRubberBand>
#include <QMouseEvent>
#include <QRect>
#include <QWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    screen = QGuiApplication::primaryScreen();
    x_press = 0;
    y_press = 0;
    x_release = 0;
    y_release = 0;
    width = 0;
    height = 0;


}

MainWindow::~MainWindow()
{
    delete ui;
}
QString text_to_copy = "";

// Обработка картинки //
void Tesseract(){



    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead("/home/kartashoow/Desktop/copytext.png");
    api->SetImage(image);
    // Get OCR result
    text_to_copy = api->GetUTF8Text();



    // Destroy used object and release memory
    api->End();
    delete api;

    pixDestroy(&image);



}





//Захват изображения //

void MainWindow::on_pushButton_clicked()
{


    const QString format = "png";
    initialPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
     if (initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += tr("/copytext.") + format;

    QFileDialog fileDialog(this, tr("Save As"), initialPath);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory(initialPath);
    QStringList mimeTypes;
    foreach (const QByteArray &bf, QImageWriter::supportedMimeTypes())
        mimeTypes.append(QLatin1String(bf));
    fileDialog.setMimeTypeFilters(mimeTypes);
    fileDialog.selectMimeTypeFilter("image/" + format);
    fileDialog.setDefaultSuffix(format);
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fileName = fileDialog.selectedFiles().first();
    if (!fragment.save(fileName)) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(fileName)));
    }


    Tesseract();
    ui->textEdit->append(text_to_copy);
}

// Выделение области

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    origin=event->pos();
    select = new QRubberBand(QRubberBand::Rectangle, 0);
    select->setGeometry(QRect(origin, QSize()));

    x_press = event->globalX();
    y_press = event->globalY();

    select->show();

    select->setWindowOpacity(0.1);


}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    select->setGeometry(QRect(origin, event->pos()).normalized());

}

void MainWindow::mouseReleaseEvent(QMouseEvent *eventREL)
{

    x_release = eventREL->globalX();
    y_release = eventREL->globalY();

    width = x_release - x_press;
    height =   y_release - y_press;
    select->hide();


    if (const QWindow *window = windowHandle())
            screen = window->screen();
    fragment = screen->grabWindow(0,x_press,y_press,width,height);

    setWindowOpacity( 1 );
    showNormal();



}



void MainWindow::on_pushButton_2_clicked()
{
    // нужно добавить удалить файл
    setWindowOpacity( 0 );
    showFullScreen();
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_2_clicked(bool checked)
{

}
