#include <stdio.h>

float func(float x){
    return x*x-3;
}
int main()
{
    float a=0,b=0; 
    for(int i=1;i<5;i++){ // finding values a and b so that f(a)<0 and f(b)>0
        if(func(i)<0 && func(i+1)>0){
            a=i;b=i+1;
            break;
        }
    }
    
    int cnt=0;
    float root=0;
    while(1 && cnt<10){ // binary seach untill f(mid)==0 or we reach approx value
        float mid=(float)(a+b)/2;
        float temp=func(mid);
        root=mid;
        printf("a = %f , b = %f --- ",a,b);
        printf("%f\n",temp);
        if(temp==0){
            break;
        }else if(temp<0)a=mid;
        else b=mid;
        cnt++;
    }
    printf("\nRoot - %.4f\n",root);
    return 0;
}
