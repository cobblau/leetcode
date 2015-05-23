/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

int maxArea(int* height, int heightSize) {
    int low, high, max;

    max = 0;

    for (low = 0, high = heightSize - 1; low <= high;) {
        int l = height[low] < height[high] ? height[low] : height[high];
        int cur = (high - low) * l;

        if (max < cur) {
            max = cur;
        }

        if (height[low] < height[high]) {
            low++;
        } else {
            high--;
        }
    }

    return max;
}
