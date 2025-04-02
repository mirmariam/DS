//Creation of doubly linked list 

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * prev;
    struct Node * next;
};

int main() {

    struct Node * N1;
    struct Node * N2;
    struct Node * N3;
    struct Node * N4;

    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));

    //Link node N1
    N1 -> next = N2;
    N1 -> prev = NULL;

    //Link node N2
    N2 -> next = N3;
    N2 -> prev = N1;

    //Link node N3
    N3 -> next = N4;
    N3 -> prev = N2;

    //Link node N4
    N4 -> next = NULL;
    N4 -> prev = N3;


    return 0;
}