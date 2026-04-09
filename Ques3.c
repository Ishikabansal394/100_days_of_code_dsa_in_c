/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left */
#include <stdio.h>      
int main() {
           int n;
    printf("enter the number of element in array\n");
    scanf("%d",&n);

    int arr[100];
    printf("enter array elements\n");



    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int d;
            printf("enter the position where u want to delete\n");
            scanf("%d",&d);

            for(int i=d-1;i<n-1;i++)
                arr[i]=arr[i+1];

            n--;

            for(int i=0;i<n;i++)
                printf("%d ",arr[i]);

            
}