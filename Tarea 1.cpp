// Tarea 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif
#define N 24

//suma de matrices de dos nxm
using namespace std;

#include<iostream>
using namespace std;
int main()
{
    int first[20], second[20], sum[20], c, n;

    cout << "Enter the number of elements in the array ";
    cin >> n;

    cout << "Enter elements of first array" << endl;

    for (c = 0; c < n; c++)
        cin >> first[c];

    cout << "Enter elements of second array" << endl;

    for (c = 0; c < n; c++)
        cin >> second[c];

    cout << "Estableciendo la cantidad de Hilos!\n";
    int nHilos;
    cout << "Cuantos hilos quieres trabajar: ";
    cin >> nHilos;

#ifdef _OPENMP
    omp_set_num_threads(nHilos);
#endif

#pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        cout << "El thread " << tid << " esta en marcha " << endl;
        cout << "El thread " << tid << " ha terminado " << endl;

    }

    cout << "Sum of elements of the arrays:" << endl;

    for (c = 0; c < n; c++) {
        sum[c] = first[c] + second[c];
        cout << sum[c] << endl;
    }
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
