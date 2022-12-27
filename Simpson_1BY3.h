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

    // formula - 1/3((y0+y1)+4(y1+y3+y5..)+2*(y2+y4+y6+..))
    
    for(int i=1;i<b;i++){
        float ind=a+(i*h);
        if(i%2==0){
            sum+=(2*valueat(ind));
        }else{
            sum+=(4*valueat(ind));
        }
    }
    sum=sum*h/3;
    printf("value of integral - %f\n",sum);
}
