#include<stdio.h>
int main(){
int i,j,k,line;
printf("enter no.of lines:");
scanf("%d",&line);
int n=(line+1)/2;//always takes odd count
//1st half
for(i=1;i<=n;i++){

    for(j=i;j<n;j++){
        printf(" ");}

    for(k=1;k<=i;k++){
        printf("* ");}

        printf("\n");
}
//2nd half
/*for(i=n-1;i>=1;i--){//n-1 for alignment in 2nd half

 for(j=n;j>i;j--){
        printf(" ");}

    for(k=1;k<=i;k++){
        printf("* ");}

        printf("\n");
}
return 0;
}
------------------------------ALITER OPTION BELOW-----------------
*/
 for(i=2;i<=n;i++){
//i=2 use to reduce 1 time execution at first for diamond look
    for(j=1;j<i;j++){
            printf(" ");
        }
        for(k=n;k>=i;k--)
        {
            printf("* ");
        }
        printf("\n");

    }
    return 0;
}
