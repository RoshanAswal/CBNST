#include <stdio.h>
#include <math.h>
float func(float x){ 
    return (x*x*x)-2*x-5;
}
float func1(float x,float y){ // f(x)=x like - for (2x^3-2x-5) we can write -  x = ((2x+5)/2)^1/3
    return (x*func(y)-y*func(x))/(func(y)-func(x));
}
int main()
{
    float a=0,b=0; 
    for(float i=1;i<5;i++){ // finding values a and b so that f(a)<0 and f(b)>0
        if(func(i)<0 && func(i+1)>0){
            a=i;b=i+1;
            break;
        }
    }

    float mid=0;
    int cnt=0;
    while(1 && cnt<10){ 
        mid=func1(a,b); // finding mid element using a function and rest is like bisection method
        int temp=func(mid);
        if(temp==0)break;
        else if(temp<0)a=mid;
        else b=mid;
        printf("%f \n",mid);
        cnt++;
    }
    printf("\nRoot - %.4f\n",mid);
    return 0;
}
