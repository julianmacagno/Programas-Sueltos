#include "ordenamiento.h"

Ordenamiento::Ordenamiento()
{

}

void Ordenamiento::generarVector(int *v, long n)
{
    v = new(std::nothrow) int[n];

    srand(time(NULL));

    for(int i=0; i<n; i++)
    {
        v[i] = (rand() % 5);
    }

    qDebug() << "Listo... el arreglo v ha sido creado en memoria" << endl;
}

bool Ordenamiento::verificar (int *v, long n)
{
   for( long i=0; i < n-1; i++ )
   {
       if( v[i] > v[i+1] ) return false;
   }
   return true;
}

void Ordenamiento::intercambio (int *v, long n)
{
  // metodo de la Burbuja
  // Orden:  n^2
  bool ordenado = false;
  for(long i=0; i < n-1 && !ordenado; i++)
  {
        ordenado = true;
        for( long j=0; j < n-i-1; j++)
        {
             if (v[j] > v[j+1])
             {
                   ordenado = false;
                   int aux = v [j];
                   v [j] = v [j+1];
                   v [j+1] = aux;
             }
        }
  }
}

void Ordenamiento::seleccion (int *v, long n)
{
  // metodo de Seleccion Directa
  // Orden:  n^2
  for (long i = 0; i < n - 1; i++)
  {
        for (long j = i + 1; j < n; j++)
        {
             if (v[i] > v[j])
             {
                   int aux = v [j];
                   v [j] = v [i];
                   v [i] = aux;
             }
        }
  }
}

void Ordenamiento::insercion (int *v, long n)
{
  // metodo de Insercion Directa
  // Orden:  n^2
  for (long j = 1; j < n; j++)
  {
        int y = v[j];
        long k;
        for (k = j-1; k >= 0 && y < v[k]; k--)
        {
              v[k+1]= v[k];
        }
        v[k+1]= y;
  }
}

void Ordenamiento::quickSort (int *v, long n)
{
   // metodo de Intercambio compuesto
   // Orden:   n*log(n)
   ordenar (v, 0, n - 1);
}

void Ordenamiento::ordenar (int *v, long izq, long der)
{
   long i = izq, j = der;
   //int  x = v[(izq + der) / 2];
   int x = v[izq];
   do
   {
        while (v[i] < x && i < der) i++;
        while (x < v[j] && j > izq) j--;
        if (i <= j)
        {
              int y = v[i];
              v[i] = v[j];
              v[j] = y;
              i++;
              j--;
        }
   }
   while (i <= j);
   if ( izq < j ) ordenar(v, izq, j);
   if ( i < der ) ordenar(v, i, der);
}

void Ordenamiento::heapSort(int *v, long n)
{
   // metodo de Seleccion compuesto
   // Orden:  n*log(n)
   long i, s, f;
   int e,  valori;

   // crear el grupo inicial...
   for (i = 1; i < n; i++)
   {
        e = v [i];
        s = i;
        f = (s-1)/2;
        while (s>0 && v[f] < e)
        {
              v[s] = v[f];
              s = f;
              f = (s-1)/2;
        }
        v[s] = e;
   }

   // se extrae la raiz, y se reordena el v y el grupo...
   for (i = n-1; i>0; i--)
   {
        valori = v[i];
        v[i] = v[0];
        f = 0;
        if (i == 1) s = -1; else s = 1;
        if (i > 2 && v[2] > v[1])  s = 2;
        while ( s >= 0 && valori < v[s])
        {
              v[f] = v[s];
              f = s;
              s = 2*f + 1;
              if (s + 1 <= i - 1 && v[s] < v[s+1]) s++;
              if (s > i - 1) s = -1;
        }
        v[f] = valori;
   }
}

void Ordenamiento::shellSort(int *v, long n)
{
   // metodo de Insercion compuesto
   // Orden:   nunca superior a n^(3/2) con serie de incrementos = 1, 4, 13, 40, 121...
   long k, h;
   int y;
   for (h = 1; h <= n / 9; h = 3*h + 1);
   for ( ; h > 0; h /= 3)
   {
         for(long j = h; j < n; j++)
         {
              int y = v[j];
              for (k = j - h; k >= 0 && y < v[k]; k-=h)
              {
                   v[k+h] = v[k];
              }
              v[k+h] = y;
         }
   }
}
