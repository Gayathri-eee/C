#include<stdio.h>
int main(){
    int num;
    printf("enter number to square it:");
    scanf("%d",&num);
    num*=num;
    printf("square of given number : %d\n",num);
    return 0;
}