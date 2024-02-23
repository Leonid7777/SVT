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