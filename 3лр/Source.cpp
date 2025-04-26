// --- main 
#include "stdafx.h"
#include <iostream>
#include <iomanip> 
#include <ctime>
#include "Salesman.h"
#define N 5
int main()
{
    setlocale(LC_ALL, "rus");
    int d[N][N] = { //0   1    2    3     4        
                  {  INF,  20, 31,  INF,   10},    //  0
                  { 10,   INF,  25,  58,   74},    //  1
                  { 12,  30,   INF,  86,   59},    //  2 
                  { 27,  48,  40,   INF,   30},    //  3
                  { 83,  76,  52,  23,   INF} };   //  4 



    int r[N];                    
    int t1 = clock();
    int s = salesman(
        N,        
        (int*)d,          // [in]  [n*n]
        r           // [out] [n]

    );
    int t2 = clock();
    std::cout << std::endl << "--e -- ";
    std::cout << std::endl << "-- f: " << N;
    std::cout << std::endl << "-- w: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)

            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "--маршрут: ";
    for (int i = 0; i < N; i++) std::cout << r[i] + 1 << "-->"; std::cout << 1;
    std::cout << std::endl << "-- длина    : " << s;
    std::cout << std::endl << "b     : " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
    std::cout << std::endl;
    system("pause");
    return 0;
}