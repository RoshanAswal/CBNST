#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// not in syllabus
double f(double x)
{
    return (pow(x, 3) - (4 * x) - 9);
}
double formula(double a, double b)
{
    double y;
    y = b - ((b - a) / (f(b) * f(a)) * f(b));
    return y;
}
int main()
{
    int a = INT_MAX, b = INT_MIN;
    int i = 1;
    double calc;
    while (a > 0 && b < 0)
    {
        calc = f(i);
        if (calc < 0)
            a = i;
        if (calc > 0)
            b = i;
        i++;
    }
    double a1 = a / 1.0;
    double b1 = b / 1.0;
    double x = -1;
    double prev_x = -2;
    int j = 0;
    while (j < 1000)
    {
        double f_a = f(a1);
        double f_b = f(b1);
        prev_x = x;
        x = formula(a1, b1);
        double f_x = f(x);
        a1 = b1;
        b1 = x;
        printf("Value of x = %lf\n", x);
        j++;
    }

    return 0;
}
