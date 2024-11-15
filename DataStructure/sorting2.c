#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

void fill(int A[]) {
    for (int i = 0; i < N; i++) {
        A[i] = rand();
    }
}

void swap(int A[], int x, int y) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

void SelectionSort(int A[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(A, i, min);
        }
    }
}

void Insertion(int A[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

int Partition(int A[], int lb, int ub) {
    int pivot = A[lb];
    int start = lb;
    int end = ub;
    while (start < end) {
        while (A[start] <= pivot) {
            start++;
        }
        while (A[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(A, start, end);
        }
    }
    swap(A, lb, end);
    return end;
}

void Quick(int A[], int lb, int ub) {
    if (lb < ub) {
        int pivloc = Partition(A, lb, ub);
        Quick(A, lb, pivloc - 1);
        Quick(A, pivloc + 1, ub);
    }
}

void Merge(int A[], int lb, int mid, int ub) {
    int* B = (int*)malloc((ub - lb + 1) * sizeof(int));
    int i = lb, j = mid + 1, k = 0;

    while (i <= mid && j <= ub) {
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while (i <= mid) {
        B[k++] = A[i++];
    }

    while (j <= ub) {
        B[k++] = A[j++];
    }

    for (k = 0; k < (ub - lb + 1); k++) {
        A[lb + k] = B[k];
    }
    free(B);
}

void MergeSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        MergeSort(A, lb, mid);
        MergeSort(A, mid + 1, ub);
        Merge(A, lb, mid, ub);
    }
}

void MaxHeapify(int A[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && A[l] > A[largest]) {
        largest = l;
    }
    if (r < n && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(A, i, largest);
        MaxHeapify(A, n, largest);
    }
}

void heapSort(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(A, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(A, 0, i);
        MaxHeapify(A, i, 0);
    }
}

void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int main() {
    int n = N; // Set the number of elements to sort (100,000)
    clock_t start, end;
    double time;
    int A[N];

    // Selection Sort
    fill(A);
    start = clock();
    SelectionSort(A, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("TIME COMPLEXITY FOR SELECTION SORT IS %f\n", time);

    // Insertion Sort
    fill(A);
    start = clock();
    Insertion(A, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("TIME COMPLEXITY FOR INSERTION SORT IS %f\n", time);

    // QuickSort
    fill(A);
    start = clock();
    Quick(A, 0, n - 1);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("TIME COMPLEXITY FOR QUICK SORT IS %f\n", time);

    // MergeSort
    fill(A);
    start = clock();
    MergeSort(A, 0, n - 1);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("TIME COMPLEXITY FOR MERGE SORT IS %f\n", time);

    // HeapSort
    fill(A);
    start = clock();
    heapSort(A, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("TIME COMPLEXITY FOR HEAP SORT IS %f\n", time);

    return 0;
}
