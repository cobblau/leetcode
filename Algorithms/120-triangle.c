/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/


int min3(int a, int b, int c) {
    if (a >= b) {
        return b > c ? c : b;
    } else {
        return a > c ? c : a;
    }
}

int minimumTotal(int **triangle, int numRows) {
    int s[numRows][numRows], min;

    s[0][0] = triangle[0][0];

    for (int i = 1; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == i) {
                s[i][j] = s[i-1][j-1] + triangle[i][j];
                continue;
            }

            if (j == 0) {
                min = s[i-1][j] > s[i-1][j+1] ? s[i-1][j+1] : s[i-1][j];
                s[i][j] = min + triangle[i][j];
                continue;
            }

            min = min3(s[i-1][j-1], s[i-1][j], s[i-1][j+1]);
            s[i][j] = min + triangle[i][j];
        }
    }

    min = s[numRows-1][0];
    for (int i = 1; i < numRows; i++) {
        if (s[numRows-1][i] < min)
            min = s[numRows-1][i];
    }

    return min;
}
