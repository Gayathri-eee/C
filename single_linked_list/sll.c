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
    printf("now single linked list is:\n");
    while(ptr!=NULL){
        printf("%d - %d\n",ptr->data,ptr->addr);
        ptr = ptr->addr;
    }
}

s* add_at_start(int d, s *head){
    s *p1= create_node(d);
    p1 -> addr =head;
    head = p1;
    return head;
} 

s* add_at_certain_pos(int d, int p, s *head){
    s *newp = create_node(d);
    s *ptr=head;
    if(p<=0){
        printf("Invalid position\n");
        return head;
    }
    if(p==1){
        newp->addr=head;
        head = newp;
        return head;
    }
    while(p>2 &&ptr!=NULL){
        ptr = ptr->addr;
        p--;
    }
    if(ptr==NULL){
        printf("Out of position\n");
        free(newp);
    }
    else{
    newp->addr=ptr->addr;
    ptr->addr=newp;
    }
    return head;
}

int main()
{
    s *head =NULL;
    s *ptr =NULL;
    int n, val, pos;
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
    while(1){
        printf("\n");
        printf("OPTIONS to functions of SLL:\n");
        printf("1) Add node at beginning\n");
        printf("2) Add node at certain position\n");
        printf("3) Add node at end\n");
        printf("4) delete node at beginning\n");
        printf("5) delete node at certain postion\n");
        printf("6) delete node at end\n");
        printf("7) to exit from program\n");
        int choice;
        printf("\n");
        printf("enter your option:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to add at beginning: ");
                scanf("%d", &val);
                head = add_at_start(val, head);
                show(head);
                break;
            case 2:
                printf("Enter data & position of node to add: ");
                scanf("%d", &val);
                scanf("%d", &pos);
                head = add_at_certain_pos(val,pos,head);
                show(head);
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}