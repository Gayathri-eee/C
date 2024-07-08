#include <stdio.h>
#include <stdlib.h>
typedef struct node scl;
struct node{
    int data;
    scl* addr;
};
scl* create_node_scl(int d){
    scl *head=malloc(sizeof(scl));
    head->data=d;
    head->addr=head;
    return head;
}

void show(scl *head){
    scl *ptr=head;
    printf("single circular linked list for given no.of nodes:\n");
    do{
        printf("%d - %p\n",ptr->data,ptr->addr);
        ptr=ptr->addr;
    }while(ptr!=head);
}
void add_at_end(int d,scl *head){
    scl* t=head;
    scl* temp=create_node_scl(d);
    while(t->addr!=head){
        t=t->addr;
        }
    t->addr=temp;
    temp->addr=head;
    return;
}
int main() {
    scl *head=NULL;
    scl *ptr=NULL;
    int n,val,d;
    printf("enter no.of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter data for node%d:",i+1);
        scanf("%d",&val);
        scl *new_node = create_node_scl(val);
        if(i==0){
            head = new_node;
            ptr = new_node;
        }
        else{
            ptr->addr=new_node;
            ptr = new_node;
        }
    }
    if(ptr!=NULL){//link last node to head
        ptr->addr=head;
    }
    show(head);
    printf("enter data to insert new node at end:");
    scanf("%d",&d);
    printf("After inserting my new node...");
    add_at_end(d,head);
    show(head);
    return 0;
}
