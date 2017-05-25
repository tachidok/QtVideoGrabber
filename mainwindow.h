#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtDebug>
#include <QImage>
#include <QPixmap>

#include <string>

#include "src/cc_grabber.h"

#define TIMER_TIMEOUT 1000

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTimer *Timer;

    CCGrabber *Grabber_pt;

public slots:

    void trigger_frame_capture();

private slots:
    void on_btn_open_video_clicked();
};

#endif // MAINWINDOW_H
