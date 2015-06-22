/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

int search(int* nums, int numsSize, int target) {
    int start = 0, end = numsSize - 1;

    while (start < end) {
        int mid = (start + end) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] <= nums[end]) {
            if (nums[mid] < target && nums[end] >= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else {
            if (nums[mid] > target && nums[start] <= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }

    return nums[start] == target ? start : -1;
}
/*
int main()
{
    int a[] = {6,7,1,2,3,4,5};

    for (int i = 0; i < 8; i++) {
        printf("%d\n", search(a, sizeof(a)/sizeof(int), i));
    }
}
*/
