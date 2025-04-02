//Implement a recursive C function to find all subsets of an array that sum to a given target, with the constraint that no two consecutive elements can be included (e.g. for array {1, 2, 3, 4} and target 4, subsets are {1,3} and {4}). Print all valid subsets.

#include <stdio.h>

void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void findSubsets(int arr[], int n, int index, int subset[], int subsetSize, int currentSum, int target) {
    if (currentSum == target) {
        printSubset(subset, subsetSize);
        return;
    }
    if (index >= n) return;

    // Include current element if not consecutive
    subset[subsetSize] = arr[index];
    findSubsets(arr, n, index + 2, subset, subsetSize + 1, currentSum + arr[index], target);

    // Exclude current element
    findSubsets(arr, n, index + 1, subset, subsetSize, currentSum, target);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    int subset[n];

    printf("Enter target: ");
    scanf("%d", &target);
     
    printf("Subsets summing to %d are:\n", target);
    findSubsets(arr, n, 0, subset, 0, 0, target);

    return 0;
}
