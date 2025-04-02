//Linked list creation, traversal, insertion at first

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head) {
    struct Node *ptr = head;

    do {
        printf("Element is %d\n", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != head);
}

struct Node * insertAtFirst(struct Node *head, int data) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node * p = head -> next;

    while (p->next != head) {
        p = p->next;
    }
    //At this point, p points to the last node of this circular linked list
    
    p -> next = ptr;
    ptr -> next = head;
    head = ptr;
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
    head->data = 7;
    head->next = second;

    //Link second and third nodes
    second->data = 5;
    second->next = third;

    //Link third and fourth nodes
    third->data = 23;
    third->next = fourth;

    //Link fourth and last nodes
    fourth->data = 9;
    fourth->next = head;

    printf("Circular linked list before insertion: \n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 80);

    printf("\nCircular linked list after insertion: \n");
    linkedListTraversal(head);

    return 0;
}