#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Format = "NTSC";
    Device = "/dev/video1";

    Timer = new QTimer(this);

    connect(Timer, SIGNAL(timeout()), this, SLOT(trigger_frame_capture()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::trigger_frame_capture()
{
    int r;

    // Initialise stuff
    FD_ZERO (&FDS);
    FD_SET (FD, &FDS);
    TV.tv_sec = 2;
    TV.tv_usec = 0;

    // FD is in grabber.cpp !!!!!!!
    r = select (FD + 1, &FDS, NULL, NULL, &TV);
    if (r == -1)
     {
      GRABBER_ERROR("select");
     }

    if (r == 0)
     {
      fprintf (stderr, "select timeout\n");
      //continue;
     }

    qDebug() << "Before read_frame()";

    // function in grabber.h!!!!!!!!
    read_frame();

    qDebug() << "After read_frame()";

    //QImage::Format_RGB32
    int bpl = Width*3;
    // Use QImage::Format_RGB888 for a 3 channels image
    QImage qimage(data_video, Width, Height, bpl, QImage::Format_RGB888);
    ui->lbl_image->setPixmap(QPixmap::fromImage(qimage));

}

void MainWindow::on_btn_open_video_clicked()
{
    // function in grabber.cpp!!!!!!!!
    abrir_video(Format, Device);

    Timer->start(TIMER_TIMEOUT);

}
