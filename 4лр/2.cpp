#include <iostream>
#include <cstdlib>
#include <ctime>

int min3(int x1, int x2, int x3) {
    return std::min(std::min(x1, x2), x3);
}

int levenstein(int lx, int l2, const char* x, int l1, const char* y) {
    int** matrix;
    matrix = new int* [l1 + 1];

    for (int i = 0; i <= l1; ++i) {
        matrix[i] = new int[l2 + 1];
    }

    for (int i = 0; i <= l1; ++i) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= l2; ++j) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            int cost = (x[i - 1] == y[j - 1]) ? 0 : 1;
            matrix[i][j] = min3(matrix[i - 1][j] + 1,
                matrix[i][j - 1] + 1,
                matrix[i - 1][j - 1] + cost);
        }
    }

    int rc = matrix[l1][l2];

    for (int i = 0; i <= l1; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return rc;
}