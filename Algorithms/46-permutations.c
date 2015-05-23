/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

/*
 * Hint:
 *   This is a Traditional backtrace problem. Stop tracing if the element already exist in trace tree.
 */

int judge(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == a[n]) {
            return 0;
        }
    }

    return 1;
}

int** permute(int* nums, int numsSize, int* returnSize) {
    int **ret, total, pos;
    int s[numsSize];

    total = numsSize;
    for (int i = numsSize - 1; i >= 1; i--) {
        total *= i;
    }

    ret = (int**) malloc(total * sizeof(int*));
    pos = 0;

    int k = 0;
    s[0] = -1;
    while (k >= 0) {

        s[k] += 1;
        while (s[k] < numsSize && !judge(s, k)) {
            s[k] += 1;
        }

        if (s[k] < numsSize) {
            if (k == numsSize - 1) {
                // find a solution
                int *t  = malloc(numsSize * sizeof(int));
                for (int i = 0; i < numsSize; i++) {
                    t[i] = nums[s[i]];
                }

                ret[pos++] = t;
            } else {
                k++;
                s[k] = -1;
            }
        } else {
            k--;
        }
    }


    *returnSize = pos;
    return ret;
}

/*
int main(int argc, char **args)
{
    int num[3] = {1,2,3};
    int **ret, n;

    ret = permute(num, 3, &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/
