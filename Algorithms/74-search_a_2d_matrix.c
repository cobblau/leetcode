/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */

/*
 Description:
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */

bool searchArray(int *arr, int size, int target) {
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == target) {
            return true;
        }

        if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int start = 0, end = matrixRowSize - 1;

    while (start < end) {
        int mid = (start + end) / 2;

        if (matrix[mid][0] == target) {
            return true;
        }

        if (matrix[mid][0] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return searchArray(&matrix[start], matrixColSize, target);
}
