#include<stdio.h>
int main(){
    int i,k,n;
    printf("enter no.of lines:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){

        for(k=1;k<=n;k++)
        {
            printf(" * ");
        }
        printf("\n");

    }
    return 0;
}


