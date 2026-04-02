#include <stdio.h>

int findMin(int nums[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }

    return nums[left];
}

int main() {
    int nums[] = {4,5,6,7,0,1,2};
    int n = 7;

    printf("%d\n", findMin(nums, n));

    return 0;
}