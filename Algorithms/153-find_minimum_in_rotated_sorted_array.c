/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

/*
 Hint:
  use binary search
 */

int findMin(int* nums, int numsSize) {
    int start = 0;
    int end = numsSize - 1;

    if (nums[start] < nums[end]) {
        return nums[start];
    }

    while (start < end) {
        int mid = (start + end) / 2;

        /* these two if can not be reversed */
        if (nums[mid] < nums[end]) {
            end = mid;
            continue;
        }

        if (nums[mid] >= nums[start]) {
            start = mid + 1;
            continue;
        }
    }

    return nums[start];
}
