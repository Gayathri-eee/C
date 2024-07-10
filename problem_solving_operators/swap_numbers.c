//Swap two numbers without using a temporary variable using arithmetic operators.
#include<stdio.h>
int main(){
    int a,b;
    printf("enter two numbers:");
    scanf("%d %d",&a,&b);
    printf("Before swapping: %d , %d\n",a,b);
    int c;
    c=a;
    a=b;
    b=c;
    printf("After swapping: %d , %d\n",a,b);
    return 0;
}
