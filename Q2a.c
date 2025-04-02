//Design and implement a C program to merge two sorted circular linked lists into a single sorted circular linked list. Also handle edge cases. (e.g. empty lists)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // Circular link
    return newNode;
}

Node* insertSorted(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!head) return newNode;

    Node *current = head;
    if (data < head->data) { // Insert before head
        while (current->next != head) current = current->next;
        current->next = newNode;
        newNode->next = head;
        return newNode;
    }

    while (current->next != head && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* mergeLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node *merged = NULL, *temp = head1;
    do {
        merged = insertSorted(merged, temp->data);
        temp = temp->next;
    } while (temp != head1);

    temp = head2;
    do {
        merged = insertSorted(merged, temp->data);
        temp = temp->next;
    } while (temp != head2);

    return merged;
}

void displayList(Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node *list1 = NULL, *list2 = NULL;
    list1 = insertSorted(list1, 1);
    list1 = insertSorted(list1, 3);
    list1 = insertSorted(list1, 5);

    list2 = insertSorted(list2, 2);
    list2 = insertSorted(list2, 4);
    list2 = insertSorted(list2, 6);

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    Node* mergedList = mergeLists(list1, list2);
    printf("Merged List: ");
    displayList(mergedList);

    return 0;
}
