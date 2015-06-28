/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

int removeDuplicates(int* nums, int numsSize) {
    int dup = 0;

    if (numsSize == 0) {
        return 0;
    }

    int first = 1, second = 1;

    while (second < numsSize) {
        if (nums[first-1] != nums[second]) {
            nums[first++] = nums[second++];
            dup = 0;
        } else {
            dup++;

            if (dup >= 2) {
                second++;
            } else {
                nums[first++] = nums[second++];
            }
        }
    }

    return first;
}
