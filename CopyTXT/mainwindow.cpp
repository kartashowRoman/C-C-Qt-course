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
#include <QImageWriter>
#include <QMessageBox>
#include <QTextEdit>
#include <QRubberBand>
#include <QMouseEvent>
#include <QRect>
#include <QWidget>
#include <QShortcut>
#include <QFile>


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
    filename = "copytxt";
    text_to_copy = "";

    new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(Back()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::Tesseract(){

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();


    if(ui->comboBox->currentIndex() == 0 ){
        api->Init(NULL, "ara");
    } else if (ui->comboBox->currentIndex() == 1){
        api->Init(NULL, "chi_sim");
    } else if (ui->comboBox->currentIndex() == 2){
        api->Init(NULL, "chi_tra_vert"); // не работает
    } else if (ui->comboBox->currentIndex() == 3){
        api->Init(NULL, "eng");
    } else if (ui->comboBox->currentIndex() == 4){
        api->Init(NULL, "fra");
    } else if (ui->comboBox->currentIndex() == 5){
        api->Init(NULL, "deu");
    } else if (ui->comboBox->currentIndex() == 6){
        api->Init(NULL, "ita"); // некорректно
    } else if (ui->comboBox->currentIndex() == 7){
        api->Init(NULL, "jpn");
    } else if (ui->comboBox->currentIndex() == 8){
        api->Init(NULL, "kaz");
    } else if (ui->comboBox->currentIndex() == 9){
        api->Init(NULL, "kor");
    } else if (ui->comboBox->currentIndex() == 10){
        api->Init(NULL, "kir");
    } else if (ui->comboBox->currentIndex() == 11){
        api->Init(NULL, "fas");
    } else if (ui->comboBox->currentIndex() == 12){
        api->Init(NULL, "pol");
    } else if (ui->comboBox->currentIndex() == 13){
        api->Init(NULL, "por");
    } else if (ui->comboBox->currentIndex() == 14){
        api->Init(NULL, "rus");
    } else if (ui->comboBox->currentIndex() == 15){
        api->Init(NULL, "spa");
    } else if (ui->comboBox->currentIndex() == 16){
        api->Init(NULL, "swe");
    } else if (ui->comboBox->currentIndex() == 17){
        api->Init(NULL, "tgk");
    } else if (ui->comboBox->currentIndex() == 18){
        api->Init(NULL, "tur");
    } else if (ui->comboBox->currentIndex() == 19){
        api->Init(NULL, "uzb");
    } else if (ui->comboBox->currentIndex() == 20){
        api->Init(NULL, "vie");

    } else {
        api->Init(NULL, "eng");
    }


    /*if (api->Init(NULL, "rus")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }*/

    // Open input image with leptonica library
    Pix *image = pixRead("copytxt");
    api->SetImage(image);
    // Get OCR result
    text_to_copy = api->GetUTF8Text();



    // Destroy used object and release memory
    api->End();
    delete api;

    pixDestroy(&image);
    DeleteFile();


}

void MainWindow::DeleteFile(){
    QFile::remove(filename);
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{

    origin=event->pos();
    select = new QRubberBand(QRubberBand::Rectangle, 0);
    select->setGeometry(QRect(origin, QSize()));

    x_press = event->globalX();
    y_press = event->globalY();
    if(windowOpacity()==0){
        select->show();
    }
    select->setWindowOpacity(0.2);


}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    select->setGeometry(QRect(origin, event->pos()).normalized());

}

void MainWindow::Back(){
    setWindowOpacity( 1 );
    showNormal();
    ui->textEdit->show();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *eventREL)
{

    x_release = eventREL->globalX();
    y_release = eventREL->globalY();

    if(x_release < x_press){
        qSwap(x_release,x_press);
        qSwap(y_release,y_press);
    }

    width = x_release - x_press;
    height = y_release - y_press;


    select->hide();


    if (const QWindow *window = windowHandle())
            screen = window->screen();
    fragment = screen->grabWindow(0,x_press,y_press,width,height);

    fragment.save(filename,"PNG");


    Back();



    Tesseract();
    ui->textEdit->append(text_to_copy);
    delete select;
}



void MainWindow::on_SelectText_clicked()
{
    ui->textEdit->hide();
    setWindowOpacity( 0 );
    showFullScreen();
    ui->textEdit->clear();

}


