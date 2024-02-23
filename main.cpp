#include <iostream>
#include <cmath>

namespace {
    const double A = -1.0;
    const double B = 2;
    const double M_C = 1.0;
}

void
create_right_part(int N, double* r_part)
{
    double step = M_PI / N; 
    double val = step;

    for(int i = 1; i < N; i++) {
        r_part[i] = M_PI * M_PI * sin(val);
        val += step;
    }
}

void
find_sol(int N, double* x, double* r_part) 
{
    const double A = -1.0 * N * N;
    const double B = 2 * N * N;
    const double M_C = 1.0 * N * N;

    double* alpha = new double[N];
    double* betta = new double[N];
    double* y = new double[N];

    y[1] = B;
    alpha[1] = M_C / y[1];
    betta[1] = r_part[1] / y[1];

    for(int i = 2; i < N - 1; i++) {
        y[i] = B + A * alpha[i - 1];
        alpha[i] = M_C / y[i];
        betta[i] = (r_part[i] - A * betta[i - 1]) / y[i];
    }

    y[N - 1] = B + A * alpha[N - 2];
    betta[N - 1] = (r_part[N - 1] - A * betta[N - 2]) / y[N - 1];

    x[N - 1] = betta[N - 1];

    for(int i = N - 2; i > 0; i--) {
        x[i] = alpha[i]* x[i + 1] + betta[i];
    }

    delete[] alpha;
    delete[] betta;
    delete[] y;
}

void
test_function(int N, double* x)
{
    double l2_norm = 0, c_norm = 0;
    for(int i = 1; i < N; i++) {
        l2_norm += (x[i] - sin(M_PI * i / N)) * (x[i] - sin(M_PI * i / N));
        if (abs(x[i] - sin(M_PI * i / N)) > c_norm) {
            c_norm = abs(x[i] - sin(M_PI * i / N));
        }
    }
    std::cout << "l2_norm: " << sqrt(l2_norm) << std::endl;
    std::cout << "c_norm: " << c_norm<< std::endl;
}

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