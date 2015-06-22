/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

bool search(int* nums, int numsSize, int target) {
    int start = 0, end = numsSize - 1;

    while (start < end) {
        int mid = (start + end) / 2;

        if (nums[mid] == target) {
            return true;
        }

        if (nums[mid] < nums[end]) {
            if (nums[mid] < target && nums[end] >= target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        } else if (nums[mid] > nums[end]) {
            if (nums[mid] > target && nums[start] <= target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        } else {
            end--;
        }
    }

    return nums[start] == target ? true : false;
}
