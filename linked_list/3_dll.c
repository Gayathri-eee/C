#include<stdio.h>
#include<stdlib.h>

typedef struct node dll;

struct node{
    int data;
    dll *prev;
    dll *next;
};

dll* create_node(int d){
    dll* temp=malloc(sizeof(dll));
    temp->data=d;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

void show(dll *head){
    dll *ptr=malloc(sizeof(dll));
    ptr=head;
    printf("now the double linked list is:\n");
    while(ptr!=NULL){
        printf("prev_addr=%p  -> data=%d  -> next_addr=%p\n",ptr->prev,ptr->data,ptr->next);
        ptr = ptr->next;
    }
}

dll* add_at_start(int d,dll *head){
    dll *new_one =create_node(d);
    head->prev= new_one;
    new_one->next=head;
    head = new_one;
    return head;
}

dll* del_first(dll *head){
    dll* p1=head;
    head =head->next;
    head->prev =NULL;
    p1->next = NULL;
    free(p1);
    p1=NULL;
    return head;
}
dll* del_last(dll *head){
    dll *p1=head;
    dll *p2=NULL;
    while(p1->next != NULL){
        p1=p1->next;
    }
    p2=p1->prev;
    p2->next =NULL;
    p1->prev=NULL;
    free(p1);
    p1=NULL;
    return head;
}

int main(){
    dll *head=NULL;
    dll *ptr=NULL;
    int n, val;
    printf("enter no.of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter data for node %d:",i+1);
        scanf("%d",&val);
        dll* new_node = create_node(val);
        if(i==0){
            head = new_node;
            ptr = new_node;
        }
        else{
            ptr->next=new_node;
            new_node->prev=ptr;
            ptr=new_node;
        }
    }
    show(head);
    printf("enter data to add at 1st node:");
    scanf("%d",&val);
    head = add_at_start(val,head);
    show(head);
    printf("after deleting 1st node:\n");
    head=del_first(head);
    show(head);
    printf("after deleting last node:\n");
    head=del_last(head);
    show(head);
    return 0;
}
