//Write a C program to perform addition, subtraction, multiplication, and division of two numbers
#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,b;
    printf("enter two numbers:");
    scanf("%d %d",&a,&b);
    printf("Operations:\n\t\t1)Addition\n\t\t2)Subtraction\n\t\t3)Multiplication\n\t\t4)Division\n\t\t5)exit\n");
    while(1){int ch;
    printf("\nenter your choice:");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
       printf("\nAddition of 2 numbers: %d",a+b);
        break;
    case 2:
       printf("\nSubtraction of 2 numbers: %d",a-b);
       break;
    case 3:
        printf("\nMultiplication of 2 numbers: %d",a*b);
        break;
    case 4:
        printf("\nDivision of 2 numbers: %d",a/b);
        break;
    case 5:
        printf("\nexiting program");
        exit(0);
    default:
        printf("Invalid choice\n");
    }}
    return 0;
}
