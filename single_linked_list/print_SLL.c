//creating single linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node s;

struct node{
    int data;
    struct node* address;
};
int main(){

    s* head = malloc(sizeof(s));//1000 add
    head -> data = 1;
    head -> address=NULL;

    s* current = malloc(sizeof(s)); //2000 add
    current -> data = 2;
    current -> address=NULL;
    head -> address = current; //head 2000 current destroy
    printf("node 1:\n data = %d\n address = %d\n",head->data,head->address);
    printf("node 2:\n data = %d\n",current->data);

    current = malloc(sizeof(s));// current 3000
    current->data=3;
    current->address=NULL;
    head -> address->address=current; // *2000 -> *0 = 3000
    printf(" address = %d\n",head->address->address);
    printf("node 3:\n data = %d\n address = nil\n",current->data);
    printf("\n");
    print_list(head);
    return 0;
}

print_list(s *head)
{
    if(head==NULL){
        printf("list is empty");
        exit(0);
    }
    s *ptr = head;
    printf("each nodes data and address: \n");
    while(ptr!=NULL)
    {
       printf("\n");
       printf(" %d ",ptr->data);
       printf(" %d ",ptr->address);
       ptr=ptr->address;//for moving to next node
    }
    printf("\n");
}
