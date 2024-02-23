#include <cmath>

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
