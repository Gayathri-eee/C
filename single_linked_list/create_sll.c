#include <stdio.h>
#include <stdlib.h>

typedef struct node s;

struct node{
    int data;
    s *addr;
};

s* create_node(int d){
    s *temp = malloc(sizeof(s));
    temp -> data = d;
    temp -> addr = NULL;
    return temp;
}

void show(struct node *head){
    s *ptr = head;
    printf("The sll data's and addresses are:\n");
    while(ptr!=NULL){
        printf("%d - %d\n",ptr->data,ptr->addr);
        ptr = ptr->addr;
    }
}

int main(){
    s *head =NULL;
    s *ptr =NULL;
    int n, val;
    printf("enter no.of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter data for node %d:",i+1);
        scanf("%d",&val);
        s *new_node = create_node(val);
        if(i==0){
           head = new_node;
            ptr = new_node;
        } else {
            ptr->addr = new_node;
            ptr = new_node;
        }
    }
    show(head);
}