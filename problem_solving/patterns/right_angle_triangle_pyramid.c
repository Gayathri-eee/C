#include<stdio.h>
int main(){
    int i,j,k,n;
    printf("enter no.of lines:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++)//print *
        {
            printf("*");
        }
        for(k=1;k<n;k++)//print spaces
        {
            printf(" ");
        }
        printf("\n");
    }

}
