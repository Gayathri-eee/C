/*1) traverse and print all elements of a singly linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node s;
struct node{
    int data;
    s *address;
};
void print_sll(s *head);
int main(){

    //1st node
    s *head = malloc(sizeof(s));
    head->data = 1;
    head->address = NULL;

    //2nd node
    s *current=malloc(sizeof(s));
    current->data =2;
    current->address=NULL;

    //link 1st node address with 2nd node address
    head->address=current;

    //print elements of singly linked list
    print_sll(head);
    free(current);
    free(head);
    return 0;
}
void print_sll(s *head)
{

    s *ptr=head;
    int i=1;
    while(ptr!=NULL)
    {
            printf(" NODE %d:\n\tdata:%d\n\taddress:%p\n",i,ptr->data,ptr->address);
            ptr=ptr->address;
            i++;
    }
}

/*2) implement the function to search key/ data in the particular node and return its index
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node s;
struct node {
    int data;
    s *address;
};

// Function prototype
int search_key(s *head, int key);

int main() {
    // 1st node
    s *head = malloc(sizeof(s));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    head->data = 1;
    head->address = NULL;

    // 2nd node
    s *current = malloc(sizeof(s));
    if (current == NULL) {
        printf("Memory allocation failed\n");
        free(head);
        return 1;
    }
    current->data = 2;
    current->address = NULL;

    // Link 1st node address with 2nd node address
    head->address = current;

    // Search for a key in the linked list
    int key = 1;
    int position = search_key(head, key); // Call the search function
    if (position != -1) {
        printf("Key %d found at position %d\n", key, position);
    } else {
        printf("Key %d not found in the list\n", key);
    }

    // Free allocated memory
    free(current);
    free(head);

    return 0;
}

int search_key(s *head, int key) {
    s *ptr = head; // Start from the head node
    int index = 0;
    while (ptr != NULL) { // Traverse the list
        if (ptr->data == key) {
            return index; // Key found, return its index
        }
        ptr = ptr->address; // Move to the next node
        index++;
    }
    return -1; // Key not found
}
*/
/* 3)Write a function to insert a node at the middle of a singly linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct node s;
struct node {
    int data;
    s *address;
};

// Function prototypes
void print_sll(s *head);
void insert_middle(s **head, int data);

int main() {
    // Create the head node
    s *head = malloc(sizeof(s));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    head->data = 1;
    head->address = NULL;

    // Create second node
    s *second = malloc(sizeof(s));
    if (second == NULL) {
        printf("Memory allocation failed\n");
        free(head);
        return 1;
    }
    second->data = 2;
    second->address = NULL;

    // Link head node to second node
    head->address = second;

    // Print the list before insertion
    printf("Original list:\n");
    print_sll(head);

    // Insert a new node in the middle
    insert_middle(&head, 3);

    // Print the list after insertion
    printf("List after insertion:\n");
    print_sll(head);

    return 0;
}

void print_sll(s *head) {
    s *ptr = head;
    int i = 1;
    while (ptr != NULL) {
        printf("NODE %d:\n\tdata: %d\n\taddress: %p\n", i, ptr->data, (void*)ptr->address);
        ptr = ptr->address;
        i++;
    }
}

void insert_middle(s **head, int data) {
    // Create the new node
    s *new_node = malloc(sizeof(s));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->address = NULL;

    // If the list is empty, insert the new node as the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Calculate the total number of nodes
    int count = 0;
    s *current = *head;
    while (current != NULL) {
        count++;
        current = current->address;
    }

    // Find the middle position
    int middle = count / 2;

    // Traverse to the node just before the middle position
    current = *head;
    for (int i = 1; i < middle; i++) {
        current = current->address;
    }

    // Insert the new node
    new_node->address = current->address;
    current->address = new_node;
}
*/
