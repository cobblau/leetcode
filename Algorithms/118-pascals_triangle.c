/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

//#include <stdio.h>
//#include <stdlib.h>

int** generate(int numRows, int** columnSizes, int* returnSize) {
    int **arr, *row;
    int *cols;

    arr = (int **) malloc(sizeof(int *) * numRows);
    cols = (int *) malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; i++) {
        row = (int *) malloc(sizeof(int) * (i + 1));

        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                row[j] = 1;
                continue;
            }

            if (i > 0) {
                row[j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }

        cols[i] = i + 1;
        arr[i] = row;
    }

    *columnSizes = cols;
    *returnSize = numRows;

    return arr;
}

/*
int main()
{
    int *a, size;
    int **arr;
    arr = generate(3, &a, &size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < a[i]; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}
*/
