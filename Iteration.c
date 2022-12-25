#include <stdio.h>
#include <math.h>
float func1(float x){ // f(x)=x like - for (2x^3-2x-5) we can write -  x = ((2x+5)/2)^1/3
    return pow((((2*x)+5)/2),0.33333);
}
float func(float x){ 
    return 2*(x*x*x)-2*x-5;
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
    int err=0;
    printf("Enter the approximate decimal digit\n");
    scanf("%d",&err); // number of digits after decimal to which prev and root must match
    
    float prev=(float)(a+b)/2;
    while(1){ 
        float root=func1(prev);
        printf("%f %f\n",prev,root);
        int er1=root*(pow(10,err)); 
        int er2=prev*(pow(10,err));
        if(er1==er2)break;
        prev=root;
    }
    printf("\nRoot - %.4f\n",prev);
    return 0;
}
