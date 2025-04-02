#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertNode(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the list
void printList(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to remove duplicates from the linked list
void removeDuplicates(struct Node *head) {
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *temp = NULL;

    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;

        // Check for duplicates
        while (temp != NULL) {
            if (current->data == temp->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

int main() {
    struct Node *head = NULL;
    int n, data;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("\nOriginal List:\n");
    printList(head);

    removeDuplicates(head);

    printf("\nList after removing duplicates:\n");
    printList(head);

    return 0;
}

