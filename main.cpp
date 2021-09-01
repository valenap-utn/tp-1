#include <iostream>

using namespace std;

/* Programar 2 funciones
        1. revertir que recibe un arreglo enteros de cualquier dimensión y lo revierte, es decir, lo que está
        en el primer elemento lo intercambia con el último, el segundo con el ante último y así
        sucesivamente.
        2. Transpuesta recibe una matriz cuadrada y la convierte en su transpuesta. Como en matrices no
        podemos hacerlo genérico, la haremos para el caso de dimensión 5x5
*/

void mostrarvec(int vec[], int dim)
{
    for (int i = 0; i < dim; ++i)
        cout << vec[i] << '\t';
    cout << endl;
}

void revertirVector(int vec[], int dim)
{
    int posicionA, posicionB, valorB, recorrido;

    recorrido = dim / 2;

    for (int i = 0; i < recorrido; ++i)
    {
        posicionA = i;
        posicionB = (dim - 1) - i;
        valorB = vec[posicionB];

        //intercambio de posición los valores
        vec[posicionB] = vec[posicionA];
        vec[posicionA] = valorB;
    }
}

void mostrarmat(int m[][5], int dfil)
{
    const int dcol = 5; // solo por prolijidad

    for (int i = 0; i < dfil; ++i)
    {
        for (int j = 0; j < dcol; ++j)
        {
            cout << m[i][j] << '\t';
        }
        cout << endl;
    }
}

void matrizTranspuesta(int m[][5], int dfil)
{
    const int dcol = 5;
    int valorB;

    for (int i = 0; i < dfil; ++i)
    {
        for (int j = 0; j < dcol; ++j)
        {
            if (i > j)
            {
                valorB = m[j][i];

                //intercambio de posición los valores
                m[j][i] = m[i][j];
                m[i][j] = valorB;
            }
        }
    }
}

int main()
{
    const int dim5 = {5};
    const int dim10 = {10};

    int vec5[dim5] = {4, 11, 19, 8, 3};
    int vec10[dim10] = {23, 15, 1, 7, 6, 27, 2, 14, 12, 9};

    int matriz[dim5][dim5] = {36, 7, 19, 28, 45,
                              17, 33, 42, 3, 25,
                              22, 41, 32, 11, 9,
                              39, 47, 14, 4, 23,
                              16, 38, 8, 27, 44};

    cout << "vector de 5 elementos" << endl;
    mostrarvec(vec5, dim5);
    cout << "reverso" << endl;
    revertirVector(vec5, dim5);
    mostrarvec(vec5, dim5);

    cout << "vector de 10 elementos" << endl;
    mostrarvec(vec10, dim10);
    cout << "reverso" << endl;
    revertirVector(vec10, dim10);
    mostrarvec(vec10, dim10);

    cout << "Matriz" << endl;
    mostrarmat(matriz, dim5);
    cout << "Transpuesta" << endl;
    matrizTranspuesta(matriz, dim5);
    mostrarmat(matriz, dim5);

    return 0;
}