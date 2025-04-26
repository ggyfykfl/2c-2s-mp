#include <iostream>
#include "Knapsack.h"
#include "Knapsack.h"
#include <ctime>
#include "Knapsack.cpp"
#define NN 20
int main()
{
    setlocale(LC_ALL, "rus");
    int* v = new int[NN];
    int* c = new int[NN];
    int V = 300;
    srand(time(0));
    for (int i = 0; i <= NN; i++) {
        v[i] = rand() % 290 + 10;
    }
    for (int i = 0; i <= NN; i++) {
        c[i] = rand() % 50 + 5;
    }    short m[NN];
    clock_t  t1 = 0, t2 = 0;
    t1 = clock();
    int maxcc = knapsack_s(
        V,
        NN,
        v,
        c,
        m
    );
    t2 = clock();
    std::cout << std::endl << "-------- Задача о рюкзаке --------- ";
    std::cout << std::endl << "- количество предметов : " << NN;
    std::cout << std::endl << "- вместимость рюкзака  : " << V;
    std::cout << std::endl << "- размеры предметов    : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] << " ";
    std::cout << std::endl << "- стоимости предметов  : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] * c[i] << " ";
    std::cout << std::endl << "- оптимальная стоимость рюкзака: " << maxcc;
    std::cout << std::endl << "- вес рюкзака: ";
    int s = 0; for (int i = 0; i < NN; i++) s += m[i] * v[i];
    std::cout << s;
    std::cout << std::endl << "- выбраны предметы: ";
    for (int i = 0; i < NN; i++) std::cout << " " << m[i];
    std::cout << std::endl << std::endl;
    std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
    std::cout << std::endl << "                  (сек):   "
        << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
    std::cout << std::endl;
    system("pause");
    return 0;
}
