/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

bool judge(int *s, int k)
{
    for (int i = 1; i < k; i++) {
        if (abs(i - k) == abs(s[i] - s[k]) || s[i] == s[k])
            return false;
    }

    return true;
}

int totalNQueens(int n) {
    int s[2048] = {0}; //queue i's position is (i, s[i])

    s[1] = 0;
    int k = 1, sum = 0;

    while (k > 0) {
        s[k] += 1;

        while (s[k] <= n && !judge(s, k)) {
            s[k] += 1;
        }

        if (s[k] <= n) {
            if (k == n) {
                sum++;
            } else {
                k++;
                s[k] = 0;
            }
        } else {
            k--;  // backtrace
        }
    }

    return sum;
}
