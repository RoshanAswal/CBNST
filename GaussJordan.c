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
    
    // making matrix diagonal
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i){ // all same as Gauss Elimination but just j!=i
                float ratio=arr[j][i]/arr[i][i];
                for(int k=0;k<4;k++){
                    arr[j][k]=(arr[j][k]-(ratio*arr[i][k]));
                }                
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

    for(int i=0;i<n;i++){ // direct evaluation unlike Gauss Elimintion
        values[i]=arr[i][n]/arr[i][i];
    }    
    
    for(int i=0;i<n;i++)
        printf("%f ",values[i]);
}
