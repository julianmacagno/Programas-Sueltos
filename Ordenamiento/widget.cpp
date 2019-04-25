#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :    QWidget(parent),    ui(new Ui::Widget)
{
    ui->setupUi(this);
    manager = new Ordenamiento;
    ui->sbCantidad->setMinimum(0);
    ui->sbCantidad->setMaximum(10000000);
    timer = new QElapsedTimer;

    connect(ui->pbBubbleSort,SIGNAL(pressed()),this,SLOT(slot_pbBubbleSort()));
    connect(ui->pbHeapSort,SIGNAL(pressed()),this,SLOT(slot_pbHeapSort()));
    connect(ui->pbInsertionSort,SIGNAL(pressed()),this,SLOT(slot_pbInsertionSort()));
    connect(ui->pbMergeSort,SIGNAL(pressed()),this,SLOT(slot_pbMergeSort()));
    connect(ui->pbQuickSort,SIGNAL(pressed()),this,SLOT(slot_pbQuickSort()));
    connect(ui->pbSelectionSort,SIGNAL(pressed()),this,SLOT(slot_pbSelectionSort()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_pbBubbleSort()
{
    if(ui->sbCantidad->value() > 0)
    {
        int *v = NULL; //NO ANDA, NO CREA BIEN EL ARREGLO EN MEMORIA
        timer->start();
        manager->generarVector(v,ui->sbCantidad->value());
        qDebug() << ("Tiempo en crear el vector: " + QString::number(timer->elapsed()) +  " milisegundos.");

        for(int i = 0; i< 100; i++)
        {
            qDebug() << v[i];
        }

        timer->start();
        manager->intercambio(v,ui->sbCantidad->value());
        qDebug()  << ("Tiempo en ordenar el vector: " + QString::number(timer->elapsed()) +  " milisegundos.");
    }
}

void Widget::slot_pbInsertionSort()
{

}

void Widget::slot_pbSelectionSort()
{

}

void Widget::slot_pbQuickSort()
{

}

void Widget::slot_pbHeapSort()
{

}

void Widget::slot_pbMergeSort()
{

}
