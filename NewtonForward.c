#include <stdio.h>

int main()
{
    int n;
    printf("Enter total no. of given terms\n"); 
    scanf("%d",&n); // total number of terms given as values of x
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
    
    for(int j=2;j<=n;j++){ // for the difference table subtracting ith value from (i+1)th value 
        for(int i=0;i<=n-j;i++){
            arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
        }
    }
    // printing difference table
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i;j++){
            printf("%f\t",arr[i][j]);
        }
        printf("\n");
    }
    
    float u=(x-arr[0][0])/(arr[1][0]-arr[0][0]); // value of u=(x-lower value)/h     h=(difference between two terms)
    float u1=u;
    float y=arr[0][1];
    int fact=1;
    for(int j=2;j<=n;j++){
        y+=(u1*arr[0][j])/fact; // adding  u(u-1)/1! then u(u-2)/2! then u(u-3)/3! and so on
        fact*=j;
        u1*=(u-(j-1));
    }
    printf("value of y - %f",y);
}
