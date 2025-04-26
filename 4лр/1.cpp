#include <iostream>
#include <cstdlib>
#include <ctime>

#define _rand(min, max) (rand() % ((max) - (min) + 1) + (min))

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int lengthS1 = 300;
    const int lengthS2 = 200;
    char s1[lengthS1 + 1];
    char s2[lengthS2 + 1];

    for (int i = 0; i < lengthS1; ++i) {
        s1[i] = 'a' + _rand(0, 25);
    }
    s1[lengthS1] = '\0';

    for (int i = 0; i < lengthS2; ++i) {
        s2[i] = 'a' + _rand(0, 25);
    }
    s2[lengthS2] = '\0';

    std::cout << "S1: " << s1 << std::endl;
    std::cout << "S2: " << s2 << std::endl;

    return 0;
}