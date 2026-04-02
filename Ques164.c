#include <stdio.h>

int searchInsert(int nums[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return left;
}

int main() {
    int nums[] = {1,3,5,6};
    int n = 4;

    printf("%d\n", searchInsert(nums, n, 5));
    printf("%d\n", searchInsert(nums, n, 2));
    printf("%d\n", searchInsert(nums, n, 7));

    return 0;
}