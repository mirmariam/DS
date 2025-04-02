#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;           // The value stored in the node
    struct Node* next;  // Pointer to the next node
};

// Function to push 
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed. Cannot push %d.\n", value);
        return;
    }
    newNode->data = value;  // Assign the value
    newNode->next = *top;   // Link the new node to the current top
    *top = newNode;         // Update top to the new node
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop 
int pop(struct Node** top) {
    if (*top == NULL) {  // Check if the stack is empty
        printf("Stack is empty! Cannot pop.\n");
        return -1;  // Return error value
    }

    struct Node* temp = *top;    // Store the current top
    int poppedValue = temp->data;  // Retrieve the value
    *top = (*top)->next;         // Update the top pointer
    free(temp);                  // Free the memory of the popped node
    return poppedValue;
}

// Function to display the stack elements
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements are: ");
    struct Node* current = top;
    while (current != NULL) {  // Traverse the stack
        printf("%d ", current->data);
        current = current->next;  // Move to the next node
    }
    printf("\n");
}

// Function to peek at the top element of the stack
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;  // Return error value
    }
    return top->data;  // Return the top value
}

// Main function
int main() {
    struct Node* top = NULL;  // Initialize an empty stack
    int choice, value;

    // Loop for user input 
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Push operation
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;

            case 2:  // Pop operation
                value = pop(&top);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:  // Peek operation
                value = peek(top);
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;

            case 4:  // Display the stack
                display(top);
                break;

            case 5:  // Exit the program
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
