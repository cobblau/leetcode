/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(int *s, int k) {
    int i;
    for (i = 1; i < k; i++) {
        if (s[i] >= s[k]) {
            return 0;
        }
    }

    return 1;
}

int **combine(int n, int k, int **columnSizes, int *returnSize) {
    int i, cur, **arr, *ar, pos;
    int *columns;
    int sum1, sum2, len;
    int s[1024] = {0};

    s[1] = 0;
    cur = 1;
    sum1 = sum2 = 1;
    pos = 0;

    for (i = n; i >= (n-k+1); i--) {
        sum1 *= i;
    }

    for (i = k; i >= 1; i--) {
        sum2 *= i;
    }

    len = sum1 / sum2;

    arr = (int **) malloc(sizeof(int*) * len);
    columns = (int *) malloc(sizeof(int) * len);

    while (cur > 0) {
        s[cur] += 1;

        while (s[cur] <= n && !judge(s, cur)) {
            s[cur] += 1;
        }

        if (s[cur] <= n) {
            if (cur == k) {
                ar = (int *) malloc(sizeof(int) * k);
                for (i = 1; i <= cur; i++) {
                    ar[i-1] = s[i];
                    //printf("%d ", s[i]);
                }
                //printf("\n");

                arr[pos] = ar;
                columns[pos] = k;
                pos++;
            } else {
                cur++;
                s[cur] = 0;
            }
        } else {
            cur--;
        }
    }

    *columnSizes = columns;
    *returnSize = len;

    return arr;
}

/*
int main() {
    int **arr, size, *columns;
    int i, j;
    arr = combine(4,2, &columns, &size);
    for (i = 0; i < size; i++) {
        for (j = 0; j < columns[i]; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}
*/
