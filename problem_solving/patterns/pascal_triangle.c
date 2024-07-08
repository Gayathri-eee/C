#include<stdio.h>
//trick pascal coef=1 , coef=coef*(row-column)/column
int main(){
    int i,j,k,n;
    printf("enter no.of lines:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            printf(" ");
        }
        int pascal=1;
        for(k=1;k<=i;k++){
            printf(" %d ",pascal);
            pascal=pascal*(i-k)/k;//trick
        }
    printf("\n");
    }
    return 0;
}
