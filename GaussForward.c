#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf(" Enter the number of terms:");
    scanf("%d", &n);
    float ax[n];
    float by[n];
    float diff[n][n];
    float h = 0;
    float x = 0;
    float p = 0;
    printf("\n Enter the value of x:");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &ax[i]);
    }
    printf("\n Enter the value of y:");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &by[i]);
    }
    h = ax[1] - ax[0];
    printf("\nEnter the value of x for which you want to find y:");
    scanf("%f", &x);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diff[i][j] = 0;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        diff[i][1] = by[i + 1] - by[i];
    }
    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            diff[j][i] = diff[j + 1][i - 1] - diff[j][i - 1];
        }
    }
    printf("\nThe value inside the difference table is :\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%f ", diff[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    int i = 0;
    float y, y1, y2, y3, y4, sum = 0;
    do
    {
        i++;
    } while (ax[i] < x);
    i--;
    p = (float)(x - ax[i]) / h;
    y = by[i];
    y1 = p * diff[i][1];
    y2 = (p * (p - 1) * diff[i - 1][2]) / 2.0;
    y3 = ((p + 1) * p * (p - 1) * diff[i - 1][3]) / 6.0;
    y4 = ((p + 1) * p * (p - 1) * (p - 2) * diff[i - 2][4]) / 24.0;
    sum = y + y1 + y2 + y3 + y4;
    printf("For value of x is:%f the value of y : %f", x, sum);
    return 0;
}
