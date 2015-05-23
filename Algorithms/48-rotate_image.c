/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

void swap(int *a , int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int n = matrixRowSize;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            swap(&matrix[i][j], &matrix[n-j-1][n-i-1]);
        }
    }

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            swap(&matrix[i][j], &matrix[n-i-1][j]);
        }
    }
}
