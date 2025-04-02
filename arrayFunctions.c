//Array functions

#include<stdio.h>

int create(int arr[]);
void display(int arr[], int n, int flag);
void search(int arr[], int n);
int insertion(int arr[],int n);
void deletion(int arr[], int n);

int main() {

  int arr[100], n;

  n = create(arr);
  display(arr, n, 0);
  search(arr, n);
  n = insertion(arr, n);
  deletion(arr, n);

  return 0;
}

int create(int arr[]) {

  int i, n;

  printf("Enter the length of the array: ");
  scanf("%d", &n);

  for(i = 0;i < n; i++) {
    printf("Enter the element %d: ",(i + 1));
    scanf("%d", &arr[i]);
  }

  return n;
}

void display(int arr[], int n, int flag) {
    int i;
    if(flag == 0) {
    printf("The elements of the array are:\n");
    } else {
    printf("The elements of the new array are:\n");
    }
    for (i = 0;i < n; i++) {
    printf("%d ",arr[i]);
    }
}

void search(int arr[], int n) {
    
    int i, flag = 0, x;
  
    printf("\nEnter the element to search for: ");
    scanf("%d", &x);
    for(i = 0;i < n; i++) {
        if(arr[i] == x) {
        printf("The element was found at position %d.\n", (i+1));
        flag = 1;
        }
    }
  
    if (flag == 0) {
        printf("The element was not found.\n");
    }
}

int insertion(int arr[], int n) {
   
    int i;

    //Insertion at start
    for (i = n; i > 0; i--) {
        arr[i]=arr[(i - 1)];
    }
    n++;
    printf("Enter the element at start: ");
    scanf("%d", &arr[0]);
    display(arr, n, 1);

    //Insertion at end
    printf("\nEnter the element at end: ");
    scanf("%d", &arr[n]);
    n++;
    display(arr, n, 1);

    //Insertion at n
    int p;
    printf("\nEnter the position where you want to add an element: ");
    scanf("%d", &p);
    for(i = n; i >= p; i--) {
        arr[i] = arr[(i - 1)];
    }
    printf("Enter the element at %d: ", p);
    scanf("%d", &arr[(p - 1)]);
    n++;
    display(arr, n, 1);

    return n;
}

void deletion(int arr[], int n) {
    int i;
    //Deletion at start
    for(i = 0;i < (n-1); i++) {
        arr[i] = arr[(i + 1)];
    }  
    n--;
    printf("\n//Element at start deleted//\n");
    display(arr, n, 1);

    //Deletion at end
    arr[(n - 1)] = arr[(n + 50)];
    n--;
    printf("\n//Element at end deleted//\n");
    display(arr, n, 1);

    //Deletion at n
    int p;
    printf("\nEnter the position where you want to delete an element: ");
    scanf("%d", &p);
    for (i = (p - 1);i < (n - 1); i++) {
        arr[i] = arr[(i + 1)]; 
    }
    n--;
    printf("\n//Element at %d deleted//\n", p);
    display(arr, n, 1);
}
