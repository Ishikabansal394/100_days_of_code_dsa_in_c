/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]*/
#include<stdio.h>

int main()
{
    int n;
    printf("enter the number of elements:\n");
    scanf("%d",&n);

    int arr[50];

    printf("enter array elements:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int i = 0;

    while(i < n)
    {
        if(arr[i] == 0)
        {
            for(int k=i; k<n-1; k++)
            {
                arr[k] = arr[k+1];
            }

            arr[n-1] = 0;  
        }
        else
        {
            i++;
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}