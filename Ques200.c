#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, idx;
} Pair;

void merge(Pair arr[], int l, int m, int r, int count[]) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Pair left[n1], right[n2];

    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int i = 0; i < n2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l, rightCount = 0;

    while (i < n1 && j < n2) {
        if (left[i].val <= right[j].val) {
            count[left[i].idx] += rightCount;
            arr[k++] = left[i++];
        } else {
            rightCount++;
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        count[left[i].idx] += rightCount;
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(Pair arr[], int l, int r, int count[]) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
}

int main() {
    int nums[] = {5,2,6,1};
    int n = 4;

    Pair arr[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}