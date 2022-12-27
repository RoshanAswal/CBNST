#include <stdio.h>

int main()
{
    int n;
    printf("Enter total no. of given terms\n");
    scanf("%d",&n);
    float arr[n][n+1];
    printf("Enter the values of x\n");
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i][0]);
    }
    printf("Enter the values of y\n");
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i][1]);
    }
    int x;
    printf("Enter the value of x to find\n");
    scanf("%df",&x);
    for(int j=2;j<=n;j++){
        for(int i=0;i<=n-j;i++){
            arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i;j++){
            printf("%f\t",arr[i][j]);
        }
        printf("\n");
    }
    float u=(x-arr[0][0])/(arr[1][0]-arr[0][0]);
    float u1=u;
    float y=arr[0][1];
    int fact=1;
    for(int j=2;j<=n;j++){
        y+=(u1*arr[0][j])/fact;
        fact*=j;
        u1*=(u-(j-1));
    }
    printf("value of y - %f",y);
}
