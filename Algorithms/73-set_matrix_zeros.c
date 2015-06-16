/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int corner;

    for (int i = 0; i < matrixRowSize; i++) {
        if (matrix[i][0] == 0) corner = 0;

        for (int j = 1; j < matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = matrixRowSize - 1; i >= 0; i--) {
        for (int j = matrixColSize - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }

        if (corner == 0) matrix[i][0] = 0;
    }

    return;
}
