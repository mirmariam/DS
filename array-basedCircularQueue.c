// Program to implement an array-based circular queue in C

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct CircularQueue {
    int items[SIZE];
    int front, rear;
};

void initializeQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue* q) {
    return (q->front == (q->rear + 1) % SIZE);
}

int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int value = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        return value;
    }
}

void displayQueue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        int i = q->front;
        printf("Queue elements: ");
        while (i != q->rear) {
            printf("%d ", q->items[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", q->items[i]);
    }
}

int main() {
    struct CircularQueue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    displayQueue(&q);

    dequeue(&q);
    printf("After dequeuing one element:\n");
    displayQueue(&q);

    enqueue(&q, 60);
    printf("After enqueueing 60:\n");
    displayQueue(&q);

    return 0;
}
