#include <stdio.h>
#include <stdlib.h>

typedef struct node s;

struct node {
    int data;
    s *link;
};

void create_sll( int d,int i,s *head){
    s *temp=malloc(sizeof(s));
    temp -> data = d;
    temp -> link = NULL;
     if (head == NULL) {
        head = temp;
    } else {
        s *ptr = head;
        while (ptr->link != NULL) {
            ptr = ptr ->link;
        }
        ptr ->link = temp;
    }
    printf("\ndata at node %d: %d\naddress of node %d: %d",i,d,i,(void *)temp);
}

int main(){
    s *head=NULL;
    create_sll(45,1,head);
    create_sll(56,2,head);
    create_sll(67,3,head);
    return 0;
}
