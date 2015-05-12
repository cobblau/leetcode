/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
 */

int majorityElement(int* nums, int numsSize) {
    int candidate;
    int nTimes;

    candidate = nTimes = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nTimes == 0) {
            candidate = nums[i];
            nTimes++;
        } else {
            if (candidate == nums[i])
                nTimes++;
            else
                nTimes--;
        }
    }

    return candidate;
}
