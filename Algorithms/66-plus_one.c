/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int *arr, len, pos = 0;

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (carry == 0) {
            break;
        }

        digits[i] += 1;

        if (digits[i] == 10) {
            digits[i] = 0;
            carry = 1;
        } else {
            carry = 0;
        }
    }

    len = carry ? digitsSize + 1 : digitsSize;

    arr = (int *) malloc(sizeof(int) * len);
    if (carry) {
        arr[pos++] = 1;
    }

    memcpy(arr + pos, digits, digitsSize * sizeof(int));
    *returnSize = len;

    return arr;
}
/*
int main()
{
    int a[] = {9,9,9,9}, len;

    int *arr = plusOne(a, sizeof(a) / sizeof(int), &len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
*/
