/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
    the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

/*
 Hint:

 Suppose: f[j] is the maximum subarray end with arr[j]

 Then: f[j] = max(f[j-1] + arr[j], arr[j])
*/

int maxSubArray(int* nums, int numsSize) {
    int max = 0x80000000;
    int cur = 0;

    for (int i = 0; i < numsSize; i++) {
        cur += nums[i];

        if (nums[i] > cur)
            cur = nums[i];

        if (cur > max)
            max = cur;
    }

    return max;
}
