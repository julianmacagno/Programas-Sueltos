#pragma once
#include<QWidget>
#include<QNetworkAccessManager>
#include<QUrl>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QString>
#include<QImage>
#include<QPainter>
#include<QVector>

#define CANT 10

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QNetworkAccessManager *manager;
    QImage imagen;
    int x=0;

    QVector<QImage> vector;

public slots:
    void slot_ir();
    void slot_descargaFinalizada(QNetworkReply *reply);
    void paintEvent(QPaintEvent *event);
};
