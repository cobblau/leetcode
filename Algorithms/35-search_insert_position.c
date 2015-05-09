/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
 */

int searchInsert(int* nums, int numsSize, int target) {
    int left, right, mid;

    for (left = 0, right = numsSize - 1; left < right;) {
        mid = (left + right) / 2;

        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (nums[left] < target)
        left++;

    return left;
}
