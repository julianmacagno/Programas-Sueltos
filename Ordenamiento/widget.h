#pragma once
#include <QWidget>
#include "ordenamiento.h"
#include <QElapsedTimer>

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
    Ordenamiento *manager;
    QElapsedTimer *timer;

private slots:
    void slot_pbBubbleSort();
    void slot_pbInsertionSort();
    void slot_pbSelectionSort();
    void slot_pbQuickSort();
    void slot_pbHeapSort();
    void slot_pbMergeSort();
};
