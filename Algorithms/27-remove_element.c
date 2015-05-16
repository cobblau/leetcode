/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

int removeElement(int* nums, int numsSize, int val) {
    int cnt = 0, pos = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            cnt++;
        } else {
            nums[pos++] = nums[i];
        }
    }

    return numsSize - cnt;
}
