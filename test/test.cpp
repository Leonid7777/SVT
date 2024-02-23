#include <iostream>
#include <cmath>


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