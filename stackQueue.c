#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

// Initialize a queue
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Enqueue an element into the queue
void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->arr[++q->rear] = value;
}

// Dequeue an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) { // Queue becomes empty
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Peek the front element of the queue
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

// Implementing stack using two queues
typedef struct {
    Queue q1, q2;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// Push an element into the stack
void push(Stack *s, int value) {
    enqueue(&s->q2, value); // Push the element into q2

    // Move all elements from q1 to q2
    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap the names of q1 and q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

// Peek the top element of the stack
int top(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    return peek(&s->q1);
}

// Check if the stack is empty
int isStackEmpty(Stack *s) {
    return isEmpty(&s->q1);
}

// Main function to demonstrate stack operations
int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", top(&s));

    printf("Popped element: %d\n", pop(&s));
    printf("Top element after pop: %d\n", top(&s));

    return 0;
}
