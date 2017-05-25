#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Grabber_pt = new CCGrabber("/dev/video2", "NTSC");

    Timer = new QTimer(this);

    connect(Timer, SIGNAL(timeout()), this, SLOT(trigger_frame_capture()));

}

MainWindow::~MainWindow()
{
    delete Grabber_pt;
    delete Timer;

    delete ui;
}

void MainWindow::trigger_frame_capture()
{
    qDebug() << "Before Grabber_pt->read_frame()";

    // Read a frame from the grabber
    Grabber_pt->read_frame();

    qDebug() << "After Grabber_pt->read_frame()";

    //QImage::Format_RGB32
    // Use QImage::Format_RGB888 for a 3 channels image
    QImage qimage(Grabber_pt->image_pt(), Grabber_pt->width(), Grabber_pt->height(), Grabber_pt->bpl(), QImage::Format_RGB888);
    ui->lbl_image->setPixmap(QPixmap::fromImage(qimage));

}

void MainWindow::on_btn_open_video_clicked()
{
    // Try to initialise video
    bool initialised = Grabber_pt->initialise_video();
    // Only start timer if video was correctly initialised
    if (initialised)
    {
        Timer->start(TIMER_TIMEOUT);
    }

}
