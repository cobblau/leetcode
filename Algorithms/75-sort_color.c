/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
 */


void swap(int *a, int i, int j) {
    if (a[i] == a[j])
        return;

    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void sortColors(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;

    for (int i = 0; i <= high;) {
        switch (nums[i]) {
        case 0:
            if (i == low) i++, low++;
            else swap(nums, low++, i);
            break;

        case 1:
            if (nums[high] == 0) swap(nums, i, high);
            else i++;
            break;

        case 2:
            swap(nums, i, high--);
            break;
        }
    }

    return;
}
