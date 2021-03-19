#include <iostream>
#include <array>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std;

void potencias(int beg, int end) 
{
    int my_array [400000]; 
    float new_array [400000]; 

    for(int i = beg; i < end; i++)
    {
        my_array[i] = i + 1; 
        new_array[i] = pow(my_array[i], 2); 
        //cout << new_array[i] << ", ";
    }   
    cout << "Termina el hilo" << endl;
}

int main(int argc, char **argv)
{
    auto start1 = chrono::high_resolution_clock::now();  // toma el tiempo de incio
    thread hilo1_1(potencias, 0, 400000);  // establece el thread y lo llama a realizar la funcion

    hilo1_1.join();  // espera a que termine el thread actual para retomar el main thread

    auto finish1 = chrono::high_resolution_clock::now();  // toma el tiempo de final
    chrono::duration<double> elapsed1 = finish1 - start1;  // calcula el intervalo de tiempo
   
    
    auto start2 = chrono::high_resolution_clock::now();  // toma el tiempo de incio
    thread hilo1_2(potencias, 0, 100000);
    thread hilo2_2(potencias, 100000, 200000);
    thread hilo3_2(potencias, 200000, 300000);
    thread hilo4_2(potencias, 300000, 400000);
    hilo1_2.join();
    hilo2_2.join();
    hilo3_2.join();
    hilo4_2.join();
    auto finish2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = finish2 - start2;  // calcula el intervalo de tiempo

    cout << "Tiempo recorrido 1: " << elapsed1.count() << " s\n";  // imprime el resultado
    cout << "Tiempo recorrido 2: " << elapsed2.count() << " s\n";  // imprime el resultado


    return 0;
}