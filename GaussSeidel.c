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
    
    // checking if applicable
    for(int i=0;i<n;i++){
        float sum=0;
        for(int j=0;j<n;j++)sum+=arr[i][j];
        for(int j=0;j<n;j++){
            if((sum-arr[i][j])>arr[i][i]){ // if any coefficient value in equation is smaller than sum of others than it is not applicable
                printf("not applicable\n");
                return 0;
            }
        }
    }
    
    float values[n];
    for(int i=0;i<n;i++)values[i]=0; // initially we will take value as 0;
    
    printf("Enter max itertions\n");
    int cnt;
    scanf("%d",&cnt);
    
    while(cnt){
        for(int i=0;i<n;i++){
            float sum=0;
            for(int j=0;j<n;j++){
                if(i!=j){ // sum except diagonal value
                    sum+=(values[j]*arr[i][j]);
                }
            }
            values[i]=(arr[i][n]-sum)/arr[i][i]; // (RHS of eq - sum except diagonal)/diagonal
            printf("%f\n",values[i]);
        }       
        cnt--;
    }

    for(int i=0;i<n;i++){
        printf("%f ",values[i]);
    }
}
