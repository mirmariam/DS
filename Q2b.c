//Write a C program to convert an infix expression to postfix using a stack implemented with a linked list. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, char data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top) {
    if (!*top) return '\0';
    Node* temp = *top;
    char data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

char peek(Node* top) {
    return top ? top->data : '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(const char* infix) {
    Node* stack = NULL;
    char postfix[100];
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (peek(stack) != '(') postfix[k++] = pop(&stack);
            pop(&stack);
        } else if (isOperator(ch)) {
            while (stack && precedence(peek(stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (stack) postfix[k++] = pop(&stack);
    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
