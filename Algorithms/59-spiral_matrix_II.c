/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int **arr;

    arr = (int **) malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        arr[i] = (int *) malloc(n * sizeof(int));
    }

    int k = 1, i = 0;
    while (k <= n * n) {
        // left to right
        for (int j = i; j < n - i; j++) {
            arr[i][j] = k++;
        }

        // top to bottom
        for (int j = i + 1; j < n - i; j++) {
            arr[j][n - i - 1] = k++;
        }

        // right to left
        for (int j = n - i - 2; j > i; j--) {
            arr[n - i - 1][j] = k++;
        }

        // bottom to top
        for (int j = n - i - 1; j > i; j--) {
            arr[j][i] = k++;
        }

        i++;
    }

    return arr;
}
