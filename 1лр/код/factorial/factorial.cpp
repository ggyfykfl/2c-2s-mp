#include <iostream>
#include <ctime>
#include <locale>
#include "Header.h"

int main() {
    setlocale(0, "");
    int n = 11;
    int start = clock();

    long double fact = factorial(n);
    std::cout << "Факториал " << fact << std::endl;

    int end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Время: " << time_taken  << std::endl;

    return 0;
}