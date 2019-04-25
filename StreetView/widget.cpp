#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :    QWidget(parent),    ui(new Ui::Widget)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);

    connect(ui->leDomicilio,SIGNAL(returnPressed()),this,SLOT(slot_ir()));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_descargaFinalizada(QNetworkReply *)));
    connect(ui->hsRotacion,SIGNAL(valueChanged(int)),this,SLOT(repaint()));

    vector = QVector<QImage>(360/CANT);
    ui->hsRotacion->setValue(22);
    ui->hsRotacion->setRange(0,(360/CANT)-1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_ir()
{
    QString urlBase = "http://maps.googleapis.com/maps/api/streetview?";
    QString sUrl = urlBase + "size=640x640&location=" + ui->leDomicilio->text() +
            "&heading=0&pitch=0&key=AIzaSyAizCan46yW74ayfbh2UIIclfV1ltwFsgg";

    manager->get(QNetworkRequest(QUrl(sUrl)));

    int angulo=CANT;

    for(int i=0;i<(360/CANT)-1;i++)
    {
        QString a = sUrl.left(sUrl.lastIndexOf("heading=")+8);
        a.append(QString::number(angulo));
        a.append("&pitch=0&key=AIzaSyAizCan46yW74ayfbh2UIIclfV1ltwFsgg");
        angulo+=CANT;
        manager->get(QNetworkRequest(QUrl(a)));
    }
}

void Widget::slot_descargaFinalizada(QNetworkReply *reply)
{
    imagen = QImage::fromData(reply->readAll());

    qDebug() << reply->url();

    QString sUrl = reply->url().toString();
    QString a = sUrl.remove(0,sUrl.lastIndexOf("heading=")+8);
    a.truncate(a.indexOf("&pitch="));

    vector.replace(a.toInt()/CANT,imagen);
    x++;

    if(x==360/CANT)
    {
        repaint();
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0,40,vector.at(ui->hsRotacion->value()).scaled(this->width(),this->height()-40));
}
