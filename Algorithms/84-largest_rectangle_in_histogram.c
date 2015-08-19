/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/


/*
Hint:

Use a stack to keep trace of incremental rectangles.
If the following number N is smaller than stack.top(), do stack.pop() util stack.top() <= N, compute the poped numbers' area at each pop().

*/

int max(int a, int b) {
    return a > b ? a : b;
}

int largestRectangleArea(int* height, int heightSize) {
    int ret = 0;

    int *stack = (int *) malloc(heightSize * sizeof(int));
    int pos = 0;

    for (int i = 0; i < heightSize; i++) {
        if (pos == 0 || stack[pos-1] <= height[i]) {
            stack[pos++] = height[i];
        } else {

            int count = 0;
            while (pos && stack[pos-1] > height[i]) {
                count++;
                ret = max(ret, stack[pos-1] * count);
                pos--;
            }

            while (count--) {
                stack[pos++] = height[i];
            }

            stack[pos++] = height[i];
        }
    }

    int count = 1;
    while (pos) {
        ret = max(ret, stack[pos-1] * count);
        count++;
        pos--;
    }

    free(stack);

    return ret;
}
