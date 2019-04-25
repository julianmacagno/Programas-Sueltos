#pragma once
#include"stdlib.h"
#include"time.h"
#include<QDebug>
class Ordenamiento
{
public:
    Ordenamiento();

public:
    void generarVector (int *v, long n);
    bool verificar (int *v, long n);

    void intercambio (int *v, long n);
    void seleccion (int *v, long n);
    void insercion (int *v, long n);
    void quickSort (int *v, long n);
    void heapSort(int *v, long n);
    void shellSort(int *v, long n);

private:
    void ordenar (int *v, long izq, long der);
};
