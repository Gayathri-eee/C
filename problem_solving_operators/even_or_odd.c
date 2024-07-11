//Write a C program to check whether a given number is even or odd using the modulus operator.
#include<stdio.h>
int main(){
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    if(n%2==0)
        printf("given number is even\n");
    else
        printf("given number is odd\n");
    return 0;
}