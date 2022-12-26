#include <stdio.h>
float func(float x){ // main function
    return (x*x*x)-3*x-5;
}

float deri(float x){ // derivative function
    return 3*x*x-3;
}

int main()
{
    float a=0,b=0;
    for(int i=1;i<5;i++){
        if(func(i)<0 && func(i+1)>0){
            a=i;b=i+1;break;
        }
    }
    float n=0;
    if((0-a)<b)n=a; // taking the number which is most close to 0
    else n=b;
    
    int cnt=0;
    while(1 && cnt<10){
        float next=n-func(n)/deri(n);
        if(next==n)break; // if root repeats then we found the answer
        n=next;
        printf("%f\n",n);
        cnt++;
    }
    printf("Root - %f\n",n);
}
