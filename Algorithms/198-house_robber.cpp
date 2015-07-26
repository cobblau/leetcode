/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

*/

int rob(int* nums, int numsSize) {
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
