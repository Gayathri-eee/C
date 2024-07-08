// IMPLEMENTATION OF QUEUE IN LINKED LIST
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}s;

s *f=NULL, *r=NULL, *newnode=NULL, *ptr=NULL;

int isFull(){
    if(newnode==NULL) return 1;
    else return 0;
}
int isEmpty(){
    if(f==NULL) return 1;
    else return 0;
}
void enqueue(int d){
    newnode=malloc(sizeof(s));
    if(isFull()){
        printf("Queue overflow\n");
        return;
    }
    newnode->data=d;
    newnode->next=NULL;
    if(f==NULL){
        r = newnode;
        f=newnode;
        return;
    }
    r->next= newnode;
    r=newnode;
    return;
}
int dequeue(){
    int val;
    ptr=f;
    if(isEmpty()){
        printf("queue underflow\n");
        return -1;
    }
    val=ptr->data;
    f=f->next;
    free(ptr);
    ptr=NULL;
    return val;
}
void show(){
    ptr=f;
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
}
void peak(){
    if(isEmpty()){
        printf("queue overflow\n");
        return;
    }
    printf("%d\n",f->data);
}
int main() {
    int ch,val;
    while(1){
        printf("\nOperations on Queue\n\t\t1.enqueue()\n\t\t2.dequeue()\n\t\t3.peak()\n\t\t4.print()\n\t\t5.exit\nenter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nenter data to enqueue:");
                int d;
                scanf("%d",&d);
                enqueue(d);
                break;
            case 2:
                val=dequeue();
                printf("\n%d is dequeued\n",val);
                break;
            case 3:
                printf("the peak element is:");
                peak();
                break;
            case 4:
                show();
                break;
            case 5:
                printf("\nexiting the program\n");
                exit(0);
            default:
                printf("\ninvalid choice");
        }
    }
    return 0;
}
