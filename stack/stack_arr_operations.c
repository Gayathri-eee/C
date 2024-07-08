//implementation stack of array
#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack_arr[SIZE];
int top=-1;
int isFull(){
    if(top==SIZE-1)
        return 1;
    else
        return 0;
}
void  push(int data){
    if(isFull()){
        printf("your stack is overflow");
        exit(1);
    }
    ++top;
    stack_arr[top]=data;
    return;
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
int pop(){
    int value;
    if(isEmpty()){
        printf("stack underflow\n");
        return -1;
    }
    value=stack_arr[top];
    --top;
    return value;
}
void peak(){
    if(isEmpty())
        printf("stack is empty\n");
    else
        printf("the top most element in stack is %d\n",stack_arr[top]);
    return;
}
int count(){
     return top+1;
}
void show(){
    int count=0;
    for(int i=top;i>=0;i--){
        printf("%d\n",stack_arr[i]);
        count++;
    }
}
int main() {
    int ch;
    while(1){
        printf("\nOperations on stack\n\t\t1.Push()\n\t\t2.Pop()\n\t\t3.peak()\n\t\t4.show()\n\t\t5.count()\n\t\t6.exit\nenter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\n enter data to pushed:");
                int d;
                scanf("%d",&d);
                push(d);
                break;
            case 2:
                printf("\n%d is popped",pop());
                break;
            case 3:
                peak();
                break;
            case 4:
                show();
                break;
            case 5:
                printf("count=%d\n",count());
                break;
            case 6:
                printf("\nexiting the program\n");
                exit(0);
            default:
                printf("\ninvalid choice");
        }
    }
    return 0;
}


