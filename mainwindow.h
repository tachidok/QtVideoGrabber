#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtDebug>
#include <QImage>
#include <QPixmap>

#include <string>

#include "stuff/grabber.h"

#define TIMER_TIMEOUT 1000

extern int FD;
extern int Width;
extern int Height;
extern unsigned char data_video[720*480*3];

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

    // ----------------------------------------------------------------
    // ----------------------------------------------------------------
    // Capture format
    string Format;

    // Capture device name
    string Device;

    // File descriptors set
    fd_set FDS;

    // A variable for time?
    struct timeval TV;
    // ----------------------------------------------------------------
    // ----------------------------------------------------------------

public slots:

    void trigger_frame_capture();

private slots:
    void on_btn_open_video_clicked();
};

#endif // MAINWINDOW_H
