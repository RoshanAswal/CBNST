#include <stdio.h>
#include <math.h>
#include <conio.h>
#define f(x,y) (y*y-x*x)/(y*y+x*x)
int main()
{
    float x0,y0,xn,x,y,h,k1,k2,k3,k4,k;
    int n;
    printf("Enter the initial values\n");
    scanf("%f%f",&x0,&y0);
    printf("Enter the no. interval\n");
    scanf("%d",&n);
    printf("Enter the value of x for desired y\n");
    scanf("%f",&xn);
    
    h=(xn-x0)/n;
    x=x0;y=y0;
    for(int i=0;i<=n;i++){
        k1=h*f(x,y);
        k2=h*f(x+h/2,y+k1/2);
        k3=h*f(x+h/2,y+k2/2);
        k4=h*f(x+h,y+k3);
        k=(k1+k4+2*k2+2*k3)/6;
        printf("a-%f b-%f\n",x,y);
        x+=h;
        y+=h;   
    }
}
