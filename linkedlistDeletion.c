#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

//Function to traverse
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

//CASE 1: Function to delete first element
struct Node * deleteFirst(struct Node * head) {
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//CASE 2: Function to delete element at a given index
struct Node * deleteAtIndex(struct Node * head, int index) {
    struct Node *p = head;
    struct Node *q = head -> next;
    for (int i = 0; i < index - 1; i++) {
        p = p -> next;
        q = q -> next;
    }

    p -> next = q -> next; //link the node after q with the p node
    free(q); //and free q (q is deleted)

    return head;
}

//CASE 3: Function to delete the last element
struct Node * deleteAtEnd(struct Node * head) {
    struct Node *p = head;
    struct Node *q = head -> next;
    while (q -> next != NULL) {
        p = p -> next;
        q = q -> next;
    }

    p -> next = NULL; 
    free(q); //and free q (q is deleted)

    return head;
}

//CASE 4: Function to delete element with a given value
struct Node * deleteValue(struct Node * head, int value) {
    struct Node *p = head;
    struct Node *q = head -> next;
    while (q -> data != value && q -> next != NULL) {
        p = p -> next;
        q = q -> next;
    }

    if (q -> data == value) {
        p -> next = q -> next;
        free(q);
    }

    return head;
}


int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //Link first and second nodes
    head->data = 4;
    head->next = second;

    //Link second and third nodes
    second->data = 3;
    second->next = third;

    //Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    //Link fourth and last nodes
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion: \n");
    linkedListTraversal(head);

    // head = deleteFirst(head); //for deleting first element in the linked list
    // head = deleteAtIndex(head, 2);
    // head = deleteAtEnd(head);
    head = deleteValue(head, 8);
    printf("\nLinked list after deletion: \n");
    linkedListTraversal(head);

    return 0;
}