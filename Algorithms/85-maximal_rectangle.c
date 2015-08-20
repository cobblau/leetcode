/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
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

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    if (matrix == NULL || matrixRowSize == 0 || matrixColSize == 0) {
        return 0;
    }

    int dp[1024][1024] = {0};

    int ret = 0;

    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }

        ret = max(ret, largestRectangleArea(dp[i], matrixColSize));
    }

    return ret;
}
