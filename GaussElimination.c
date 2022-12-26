#include <stdio.h>


int main()
{
    printf("Enter the number of equations\n");
    int n;
    scanf("%d",&n);
    float arr[n][n+1];
    printf("Enter the equations\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++)
            scanf("%f",&arr[i][j]);
    }
    
    // making matrix upper traingular
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float ratio=arr[j][i]/arr[i][i];
            for(int k=0;k<4;k++){
                arr[j][k]=(arr[j][k]-(ratio*arr[i][k]));
            }
        }
    }
    
    printf("matrix - \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++)
            printf("%.2f ",arr[i][j]);
        printf("\n");
    }
    
    float values[n]; // it will contain all the values of variables
    values[n-1]=(arr[n-1][n]/arr[n-1][n-1]); // computing last variable

    for(int i=n-2;i>=0;i--){
        float sum=0;
        for(int j=i+1;j<n;j++){
            sum+=(arr[i][j]*values[j]);
        }
        values[i]=arr[i][n]/sum;
    }
    
    for(int i=0;i<n;i++)
        printf("%f ",values[i]);
}
