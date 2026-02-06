/*Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:*/
#include<stdio.h>
int main()
{
    int n;
    printf("enter n");
    scanf("%d",&n);
    int arr[n];
    printf("enter array element : \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int m;
    printf("enter the element u want to remove : \n");
    scanf("%d",&m);
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==m)
        {
            c++;
            for(int j=i+1; j<n; j++)
            {
              
              arr[j-1]=arr[j];
              i=i-1;// to check the new element at index i, bcoz i moves forward in for loop
            }
        }
        else 
        {
            continue;
        }
    }
    int k=n-c;
    printf("%d",k);
    return 0;
    

}

