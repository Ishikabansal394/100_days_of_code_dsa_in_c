#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int count = 0;

    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)arr[i] > 2LL * arr[j]) j++;
        count += (j - (mid + 1));
    }

    int i = left, k = left;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }

    return count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid, right);
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("%d\n", mergeSort(arr, temp, 0, n - 1));

    return 0;
}