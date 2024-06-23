#include<stdio.h>
#include<stdlib.h>
typedef struct node s;
struct node{
    int data;
    s *link;
};
int main()
{
    s *head = malloc(sizeof(s));
    head -> data = 1;
    head -> link = NULL;
    s *node2 =malloc(sizeof(s));
    node2 -> data = 2;
    node2 -> link = NULL;
    head -> link = node2;
    node2 =malloc (sizeof(s));
    node2 -> data =3;
    node2 -> link = NULL;
    head -> link-> link = node2;
    print_list(head);
    printf("\n");
    return 0;
}
print_list( s *head)
{
    int count = 0;
    s *temp= head;
    while(temp!=NULL)
    {
        count++;
        printf(" %d %p ",temp->data, temp->link);
        temp = temp->link;
    }
    printf("\ntotal no.of nodes = %d\n",count);
}
