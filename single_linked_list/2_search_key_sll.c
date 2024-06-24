
// implement the function to search key/ data in the particular node and return its index
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

