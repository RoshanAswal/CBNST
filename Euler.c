#include <stdio.h>
#include <math.h>
#include <conio.h>
#define f(x,y) -x*y
int main()
{
    float x0,y0,xn,x,y,h;
    printf("Enter the initial values\n");
    scanf("%f%f",&x0,&y0);
    printf("Enter the value of interval\n");
    scanf("%f",&h);
    printf("Enter the value of x for desired y\n");
    scanf("%f",&xn);
    
    int n=(xn-x0)/h;
    
    for(int i=0;i<=n;i++){
        y=y0+h*f(x0,y0);
        x=x0+h;
        x0=x;y0=y;
        printf("a-%f b-%f\n",x0,y0);        
    }
}
