/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

int do_rob(int* nums, int numsSize) {
    int f[10000];

    if (numsSize <= 0) {
        return 0;
    }

    if (numsSize > 0) {
        f[0] = nums[0];
    }

    if (numsSize > 1) {
        f[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    }

    for (int i = 2; i < numsSize; i++) {
        f[i] = f[i-2] + nums[i];

        if (f[i] < f[i-1]) {
            f[i] = f[i-1];
        }
    }

    return f[numsSize-1];
}
int rob(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];

    int one = do_rob(nums, numsSize - 1);
    int two = do_rob(nums + 1, numsSize - 1);

    return one > two ? one : two;
}
