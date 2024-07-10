#include<stdio.h>
int main(){
    int a,b;
    printf("enter two numbers:");
    scanf("%d %d",&a,&b);
    printf("Before swapping:\n");
    printf("%d %d\n",a,b);
    printf("After swapping:\n");
    a=a+b;
    b=a-b;
    a=a-b;
    printf("%d %d",a,b);
}
