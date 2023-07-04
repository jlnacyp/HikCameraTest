#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hikcamera.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startPushButton_clicked();

    void on_stopPushButton_clicked();

    void on_grabPushButton_clicked();

private:
    Ui::MainWindow *ui;
    HIKCamera* camera;
};
#endif // MAINWINDOW_H
