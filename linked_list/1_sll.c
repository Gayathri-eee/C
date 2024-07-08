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
        printf("%d - %d\n",ptr->data,(void*)ptr->addr);
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

s* add_at_end(int d,s *head){
    s *temp=create_node(d);
    if(head==NULL){
        return temp;
    }
    s *ptr=head;
    while (ptr->addr != NULL) {
        ptr = ptr->addr;
    }
    ptr->addr = temp;
    return head;
}

s* delete_at_start(s *head){
    s *ptr=head;
    head = head -> addr;
    free(ptr);
    ptr=NULL;
    return head;
}

s* delete_at_certain_pos(int p, s *head) {
    if (head == NULL) {
        printf("List is already empty\n");
        return NULL;
    }
    if (p <= 0) {
        printf("Invalid position\n");
        return head;
    }
    if (p == 1) {
        s *ptr = head;
        head = head->addr;
        free(ptr);
        return head;
    }
    s *ptr = head;
    s *temp = NULL;
    while (p > 2 && ptr->addr != NULL) {
        ptr = ptr->addr;
        p--;
    }
    if (ptr->addr == NULL) {
        printf("Out of position\n");
    } else {
        temp = ptr->addr;
        ptr->addr = temp->addr;
        free(temp);
    }
    return head;
}

s* delete_at_end(s *head){
    s *ptr=head;
    s *temp = NULL;
    int n;
    if(head->addr==NULL){
        free(head);
        return NULL;
    }
    while(ptr->addr!=NULL){
        temp=ptr;
        ptr=ptr->addr;
    }
    temp ->addr = NULL;
    free(ptr);
    ptr=NULL;
    return head;
}

int counter(s *head){
    int count=0;
    s *temp=head;
    while(temp!=NULL){
        temp=temp->addr;
        count++;
    }
    return count;
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
        printf("OPTIONS to perform operations in SLL:\n");
        printf("1) Add node at beginning\n");
        printf("2) Add node at certain position\n");
        printf("3) Add node at end\n");
        printf("4) delete node at beginning\n");
        printf("5) delete node at certain position\n");
        printf("6) delete node at end\n");
        printf("7) count total no.of nodes\n");
        printf("8) to exit from program\n");
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
            case 3:
                printf("Enter data to add at end: ");
                scanf("%d", &val);
                head = add_at_end(val,head);
                show(head);
                break;
            case 4:
                printf("After delete node at beginning...\n ");
                head = delete_at_start(head);
                show(head);
                break;
            case 5:
                printf("After delete node at certain position....\n ");
                printf("Enter position of node to delete: ");
                scanf("%d", &pos);
                head = delete_at_certain_pos(pos,head);
                show(head);
                break;
            case 6:
                printf("After delete node at end....\n");
                head = delete_at_end(head);
                show(head);
                break;
            case 7:
                printf("Total number of nodes: %d\n",counter(head));
                break;
            case 8:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
