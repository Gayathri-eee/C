#include<stdio.h>
int main(){
    int i,j,k,n,val=1;
    printf("enter no.of lines:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    for(k=1;k<=i;k++)
        {

            printf(" %d ",val++);
        }
    for(j=i;j<n;j++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}


