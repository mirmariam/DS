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
    fourth->next = NULL;

    linkedListTraversal(head);

    return 0;
}

