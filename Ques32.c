#include <stdio.h>

void reverse(int arr[], int i, int j) {
    while(i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main() {
    int n, k;
    printf("enter size: ");
    scanf("%d", &n);
    int arr[100];

    printf("enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("enter k: ");
    scanf("%d", &k);

    k = k % n; 
    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
    printf("rotated array:");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}