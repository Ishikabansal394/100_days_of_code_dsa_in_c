#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int arr1[n1], arr2[n2];

    int max = 0;

    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
        if (arr1[i] > max) max = arr1[i];
    }

    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int *count = (int*)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n1; i++) {
        count[arr1[i]]++;
    }

    int idx = 0;

    for (int i = 0; i < n2; i++) {
        while (count[arr2[i]] > 0) {
            arr1[idx++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    int temp[n1], t = 0;

    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            temp[t++] = i;
            count[i]--;
        }
    }

    qsort(temp, t, sizeof(int), cmp);

    for (int i = 0; i < t; i++) {
        arr1[idx++] = temp[i];
    }

    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }

    free(count);
    return 0;
}