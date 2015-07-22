/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int *rets = (int *) malloc(numsSize * sizeof(int));

    int m = 1;
    for (int i = 0; i < numsSize; i++) {
        rets[i] = m;
        m *= nums[i];
    }

    int n = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        rets[i] *= n;
        n *= nums[i];
    }

    *returnSize = numsSize;
    return rets;
}
