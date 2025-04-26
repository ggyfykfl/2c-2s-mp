#include "Auxil.h"
#include <iostream>

int main() {
    setlocale(0, "");
    auxil::start();

    double randomDouble = auxil::dget(1.0, 10.0);
    int randomInt = auxil::iget(1, 10);

    std::cout << "Случайное действительное число: " << randomDouble << std::endl;
    std::cout << "Случайное целое число: " << randomInt <<"\n"<< std::endl;

    return 0;
}