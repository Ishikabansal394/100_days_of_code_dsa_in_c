/*Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2^x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 2^0 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 2^4 = 16
Example 3:

Input: n = 3
Output: false
*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("True");
    else
        printf("False");

    return 0;
}