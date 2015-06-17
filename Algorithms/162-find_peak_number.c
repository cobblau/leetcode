/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

/*
 * Hint: http://courses.csail.mit.edu/6.006/spring11/rec/rec02.pdf
 */
bool isPeak(int *nums, int size, int index) {
    if (index > 0 && nums[index] < nums[index-1]) {
        return false;
    }

    if (index < size-1 && nums[index] < nums[index+1]) {
        return false;
    }

    return true;
}

int findPeakElement(int* nums, int numsSize) {
    int low = 0, high = numsSize;

    while (low < high) {
        int mid = (low + high) / 2;

        if (isPeak(nums, numsSize, mid)) {
            return mid;
        }

        if (mid > 0 && nums[mid] < nums[mid-1]) {
            high = mid - 1;
            continue;
        }

        if (mid < numsSize-1 && nums[mid] < nums[mid+1]) {
            low = mid + 1;
        }
    }

    return low;
}
