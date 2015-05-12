/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given an array of integers, every element appears three times except for one. Find that single one.
 */

int singleNumber(int* nums, int numsSize) {
    int arr[32] = {0};
    int result = 0;

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < numsSize; j++) {
            if ((nums[j] >> i) & 1)
                arr[i]++;
        }

        result |= ((arr[i] % 3) << i);
    }

    return result;
}
