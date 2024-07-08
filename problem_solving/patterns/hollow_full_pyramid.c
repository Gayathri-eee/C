#include<stdio.h>
int main(){
    int i,j,k,n;
    printf("enter no.of lines:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    for(j=i;j<=(2*n/2);j++){
            printf(" ");
        }
        for(k=1;k<=(2*i-1);k++)
        {
            if(k==1||i==n||k==(2*i-1)){
            printf("*");}
            else{
            printf(" ");}
        }
        printf("\n");

    }
    return 0;
}


