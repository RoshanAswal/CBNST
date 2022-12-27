#include <stdio.h>
#include <math.h>
#include <conio.h>

float valueat(int x){
    return 1/(1+pow(x,2));
}

int main()
{
    float a,b;
    printf("Enter the values of limits\n");
    scanf("%f%f",&a,&b);
    int n;
    printf("Enter the number of intervals\n");
    scanf("%d",&n);
    
    float h=(b-a)/n; // value of stepsize
    float sum=valueat(a)+valueat(b);

    
    for(int i=1;i<b;i++){
        float ind=a+(i*h);
        sum+=(2*valueat(ind));
    }
    sum=sum*h/2;
    printf("value of integral - %f\n",sum);
}
