#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    camera = HIKCamera::getInstance();
    camera->initialize();
    camera->connect();

    ui->srcImg->setScaledContents(true);
    ui->grabImg->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startPushButton_clicked()
{
    camera->startStreaming((HWND)ui->srcImg->winId());
}


void MainWindow::on_stopPushButton_clicked()
{
    camera->stopStreaming();
}

void MainWindow::on_grabPushButton_clicked()
{
//    cv::Mat grabImg;
//    camera->startGrabbing(grabImg);
//    QImage qgrabImg = QImage((const unsigned char*)(grabImg.data), grabImg.cols, grabImg.rows, grabImg.cols*grabImg.channels(), QImage::Format_RGB888);   // Mat为BGR颜色模式;
//    qgrabImg = qgrabImg.rgbSwapped();
//    ui->grabImg->setPixmap(QPixmap::fromImage(qgrabImg));

    camera->startStreaming2((HWND)ui->grabImg->winId());
}

