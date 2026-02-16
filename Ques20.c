#include <stdio.h>


void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    int n1, n2;

    // input
    printf("enter size of first array: ");  
    scanf("%d", &n1);
    int nums1[n1];
    for(int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("enter size of second array: ");
    scanf("%d", &n2);
    int nums2[n2];
    for(int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }

    bubbleSort(nums1, n1);
    bubbleSort(nums2, n2);

    int i = 0, j = 0;
    int result[1000];
    int k = 0;

    while(i < n1 && j < n2) {
        if(nums1[i] == nums2[j]) {
            result[k++] = nums1[i];
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    // print result
    for(int x = 0; x < k; x++) {
        printf("%d ", result[x]);
    }

    return 0;
}