/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

//#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int start = 0;
    int end = numsSize - 1;

    if (nums[start] < nums[end]) {
        return nums[start];
    }

    while (start < end) {
        int mid = (start + end) / 2;

        if (nums[mid] < nums[end]) {
            end = mid;
            continue;
        }

        if (nums[mid] > nums[end]) {
            start = mid + 1;
            continue;
        }

        end--;
    }

    return nums[start];
}
/*
int main() {
    int a[] = {10, 1, 10, 10, 10};

    printf("%d\n", findMin(a, sizeof(a) / sizeof(int)));
}
*/
