//implementation stack of linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node s;

s *top = NULL;

struct node{
    int data;
    s* addr;
};

void push(int d){
    s *new_node = malloc(sizeof(s));
    if(new_node==NULL){
        printf("Stack overflow");
        exit(1);
    }
    new_node->data=d;
    new_node->addr=NULL;
    new_node->addr=top;//link top to new_node at first
    top=new_node;//top pointing new_node
}
int isEmpty(){
    if(top==NULL) return 1;
    else return 0;
}
int pop(){
    s* temp;
    temp=top;
    if(isEmpty()){
        printf("stack underflow.");
        exit(1);
    }
    int val=temp->data;
    top=top->addr;
    free(temp);
    temp=NULL;
    return val;
}
void print(){
    s* temp;
    temp=top;
    if(isEmpty()){
        printf("stack underflow.");
        exit(1);
    }
    printf("The stack elements are:\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp= temp->addr;
    }
    printf("\n");
}
int peak(){
     if(isEmpty()){
        printf("stack underflow.");
        exit(1);
    }
    return top->data;
}
int count(){
    int count=0;
    while(top!=NULL){
        top= top->addr;
        count++;
    }
    return count;
}
int main() {
    int ch;
    while(1){
        printf("\nOperations on stack\n\t\t1.Push()\n\t\t2.Pop()\n\t\t3.peak()\n\t\t4.print()\n\t\t5.count()\n\t\t6.exit\nenter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\n enter data to pushed:");
                int d;
                scanf("%d",&d);
                push(d);
                break;
            case 2:
                printf("your popped element is %d\n",pop());
                break;
            case 3:
                printf("the top element is %d\n",peak());
                break;
            case 4:
                print();
                break;
            case 5:
                printf("the nodes count is %d\n",count());
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



