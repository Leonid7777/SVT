#include <iostream>
#include <cmath>


void
test_function(int N, double* x)
{
    double val, l2_norm = 0, c_norm = 0;

    for(int i = 1; i < N; i++) {
        val = abs(x[i] - sin(M_PI * i / N));
        l2_norm += val * val;

        if (val > c_norm) {
            c_norm = val;
        }
    }

    std::cout << "l2_norm: " << sqrt(l2_norm) / N << std::endl;
    std::cout << "c_norm: " << c_norm<< std::endl;
}