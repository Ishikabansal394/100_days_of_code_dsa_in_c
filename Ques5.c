/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/
#include<stdio.h>
int main(){
    int n;
    printf("enter the number of elemnets in array : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of array : /n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k,index=-1,comparisons=0;
            printf("enter element u want to search\n");
            scanf("%d",&k);

            for(int i=0;i<n;i++)
            {  comparisons++;
                if(arr[i]==k)
                {
                    index=i;
                    break;
                }
            }

            if(index!=-1)
                {printf("%d is found at %d index",k,index);
                printf("\nComparisons = %d",comparisons);
                }
            else
                printf("element is not found");
}