#include <iostream>
#include <ctime>
#include <locale>
#include "Header.h"

long double factorial(int number) {
	if (number == 1) return 1;
	return number * factorial(number - 1);
}