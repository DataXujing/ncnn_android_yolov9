#include "widget.h"
#include "yolov9.h"

#include <QApplication>
#include <QFile>

yolov9 *yolo9 = new yolov9();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 加载QSS

    QFile qss_(":/assets/ManjaroMix.qss");
    if( qss_.open(QFile::ReadOnly)){
        qDebug("open success");
        QString style = QLatin1String(qss_.readAll());
        a.setStyleSheet(style);
        qss_.close();
    }
    else{
       qDebug("Open failed");
    }

    int target_size = 640;
    float norm_vals[3] = { 1 / 255.f, 1 / 255.f, 1 / 255.f };


    yolo9->load(target_size, norm_vals);


    Widget w;
    w.show();
    return a.exec();
}
