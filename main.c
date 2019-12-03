#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dual_quicksort(int A[], int from_index, int to_index);
void insertion_sort(int A[], int from, int to);
void swap(int* a, int* b);
void printArr(int A[], int from, int to);

void dual_quicksort(int A[], int from_index, int to_index) {
    if (to_index - from_index + 1 <= 17) {
        insertion_sort(A, from_index, to_index);
        printf("Insertion sort: ");
        printArr(A, from_index, to_index);
        return;
    }

    if (A[from_index] > A[to_index])
        swap(&A[from_index], &A[to_index]);

    int lpivot = A[from_index];
    int rpivot = A[to_index];
    int a = from_index;

    for (int i = a + 1; i < to_index; i++) {
        if (A[i] < lpivot) {
            swap(&A[i], &A[a + 1]);
            a++;
        }
    }
    printf("After moving elements less than left pivot:\n");
    printArr(A, from_index, to_index);

    int b = a;

    for (int i = b + 1; i < to_index; i++) {
        if (A[i] >= lpivot && A[i] <= rpivot) {
            swap(&A[i], &A[b + 1]);
            b++;
        }
    }
    printf("After moving elements that lie between left pivot and right pivot:\n");
    printArr(A, from_index, to_index);

    swap(&A[from_index], &A[a]);
    swap(&A[to_index], &A[b + 1]);

    printf("After final pivot swap:\n");
    printArr(A, from_index, to_index);

    dual_quicksort(A, from_index, a - 1);
    dual_quicksort(A, a + 1, b);
    dual_quicksort(A, b + 2, to_index);
}

void insertion_sort(int A[], int from, int to) {
    for (int i = from; i < to; i++) {
        for (int j = i + 1; j > from && A[j] < A[j - 1]; j--) {
            swap(&A[j], &A[j - 1]);
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int A[], int from, int to) {
    for (int i = from; i < to + 1; i++) {
        printf("%d", A[i]);
        if (i != to) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int A[n];

        for (int j = 0; j < n; j++) {
            scanf("%d", &A[j]);
        }
        dual_quicksort(A, 0, n - 1);
        printArr(A, 0, n - 1);
    }

    return 0;
}
