#include <iostream>
#include <QTime>
#include "math.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Este es el programa que realiza la Criba de Erastotenes" << endl;
    cout << "Ingrese una cantidad a continuacion:" << endl;
    cout << "1: 10 millones" << endl << "2: 100 millones" << endl << "3: 200 millones" << endl;
    int cant, op; cin >> op;

    if(op == 1)
        cant = 10000000;

    else if(op == 2)
        cant = 100000000;

    else if(op == 3)
        cant = 200000000;

    else
    {   cout << "El programa finalizara, por pelotudo. Metiste mal el numero" << endl;
        return 0;    }

    cout << endl << "A continuacion, se buscaran los numeros primos menores a " << cant << endl;
    system("pause");

    QTime timer;
    cout << "Calculando . ." << endl;
    timer.start();

    bool *v = new bool[cant];

    for (int i = 0; i< cant; i++)
    {
        v[i] = true;
    }

    for (int i = 2; i< cant; i++)
    {
        if (i*i < cant)
        {
            for (int j = 2; j*i < cant; j++)
            {
                v[j*i] = false;
            }
        }
    }

    cout << "Los numeros primos menores a " << cant << " son: " << endl;
    int j = 0;
    for (int i = 2; i<cant; i++)
    {
        if (v[i] == true)
        {
            //cout << i;
            j++;
        }
    }

    float tiempo = timer.elapsed();

    cout << "y hay " << j << " de ellos." << endl;
    cout << "El mas grande es: ";

    for (int i = cant-1; i >= 0; i--)
    {
        if (v[i] == true)
        {
            cout << i << endl << endl;
            break;
        }
    }

    cout << "Tiempo transcurrido: " << tiempo/1000 << " segundos." << endl << endl;
    system("pause");
    return 0;
}
