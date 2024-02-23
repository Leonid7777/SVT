#include <iostream>
#include <cmath>
#include <create_right_part.h>
#include <solver.h>
#include "test.h"


int
main()
{
    int N;
    std::cout << "Введите количество точек: ";
    std::cin >> N;

    double *r_part = new double[N];
    create_right_part(N, r_part);

    double* x = new double[N];

    find_sol(N, x, r_part);

    test_function(N, x);

    delete[] r_part;
    delete[] x;

    return 0;
}