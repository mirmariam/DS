#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int top;
    int disks[MAX];
} Stack;

// Function to initialize a stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int disk) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->disks[++(s->top)] = disk;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->disks[(s->top)--];
}

// Function to peek the top element of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->disks[s->top];
}

// Function to print the movement of disks
void moveDisk(char fromPeg, char toPeg, int disk) {
    printf("Move disk %d from %c to %c\n", disk, fromPeg, toPeg);
}

// Function to implement legal moves between two stacks
void moveBetweenStacks(Stack *src, Stack *dest, char s, char d) {
    int srcTopDisk = isEmpty(src) ? -1 : pop(src);
    int destTopDisk = isEmpty(dest) ? -1 : pop(dest);

    // Case 1: Source stack is empty
    if (srcTopDisk == -1) {
        push(src, destTopDisk);
        moveDisk(d, s, destTopDisk);
    }
    // Case 2: Destination stack is empty
    else if (destTopDisk == -1) {
        push(dest, srcTopDisk);
        moveDisk(s, d, srcTopDisk);
    }
    // Case 3: Top disk of source is smaller
    else if (srcTopDisk < destTopDisk) {
        push(dest, destTopDisk);
        push(dest, srcTopDisk);
        moveDisk(s, d, srcTopDisk);
    }
    // Case 4: Top disk of destination is smaller
    else {
        push(src, srcTopDisk);
        push(src, destTopDisk);
        moveDisk(d, s, destTopDisk);
    }
}

// Function to solve Tower of Hanoi using stacks
void towerOfHanoi(int numDisks, Stack *src, Stack *aux, Stack *dest) {
    char s = 'A', d = 'C', a = 'B';
    int totalMoves = (1 << numDisks) - 1; // 2^n - 1 moves

    // Fill the source stack with disks
    for (int i = numDisks; i >= 1; i--) {
        push(src, i);
    }

    // If the number of disks is even, swap the destination and auxiliary
    if (numDisks % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }

    // Perform the moves
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            moveBetweenStacks(src, dest, s, d);
        } else if (i % 3 == 2) {
            moveBetweenStacks(src, aux, s, a);
        } else if (i % 3 == 0) {
            moveBetweenStacks(aux, dest, a, d);
        }
    }
}

int main() {
    int numDisks;
    Stack src, aux, dest;

    // Initialize stacks
    initStack(&src);
    initStack(&aux);
    initStack(&dest);

    // Input the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Solve Tower of Hanoi
    printf("The sequence of moves is:\n");
    towerOfHanoi(numDisks, &src, &aux, &dest);

    return 0;
}
