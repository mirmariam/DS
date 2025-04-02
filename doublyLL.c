// Creation, traversal, insertion, and deletion in a doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverseList(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtStart(struct Node *head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    head = newNode;
    return head;
}

struct Node* deleteNode(struct Node *head, int key) {
    struct Node *ptr = head;

    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node not found!\n");
        return head;
    }

    if (ptr->prev != NULL) ptr->prev->next = ptr->next;
    if (ptr->next != NULL) ptr->next->prev = ptr->prev;
    if (ptr == head) head = ptr->next;

    free(ptr);
    return head;
}

int main() {
    struct Node *N1;
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;

    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));

    N1->data = 10; N1->prev = NULL; N1->next = N2;
    N2->data = 20; N2->prev = N1; N2->next = N3;
    N3->data = 30; N3->prev = N2; N3->next = N4;
    N4->data = 40; N4->prev = N3; N4->next = NULL;

    printf("Doubly Linked List before insertion:\n");
    traverseList(N1);

    N1 = insertAtStart(N1, 5);
    printf("\nDoubly Linked List after insertion:\n");
    traverseList(N1);

    N1 = deleteNode(N1, 20);
    printf("\nDoubly Linked List after deletion:\n");
    traverseList(N1);

    return 0;
}
