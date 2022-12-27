#include <stdio.h>
#include <stdlib.h>
// x 1 2 3 4 5
//  y 1200 900 600 200 110 50
int main()
{
    int i, j, n;
    float x[10], y[10], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, a, b;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the values of x and y: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }
    for (i = 0; i < n; i++)
    {
        sumx = sumx + x[i];
        sumy = sumy + y[i];
        sumxy = sumxy + x[i] * y[i];
        sumx2 = sumx2 + x[i] * x[i];
    }
    a = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    b = (sumy - a * sumx) / n;
    printf("The straight line is: y = %f + %fx", b, a);

    return 0;
}
