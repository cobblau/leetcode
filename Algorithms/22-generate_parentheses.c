/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

/*
 * Hint:
 *  use backtracing
 */

int judge(int *s, int len, int cap) {
    int left = 0, right = 0;
    for (int i = 1; i <= len; i++) {
        if (s[i] == 0) {
            left++;
        } else {
            right++;
        }

        if (right > left) {
            return 0;
        }
    }

    if (left > cap / 2) {
        return 0;
    }

    return 1;
}

char** generateParenthesis(int n, int* returnSize) {
    int s[1024] = {-1};   // solution footprint, the value is the position in ss
    char ss[2] = {'(', ')'}; // solution tree
    int k = 1;

    int num = 0, total = 2 * n;

    // actually the maximum size if pow(2, total), here we just use 4096
    char **ret = (char **) malloc(sizeof(char*) * 4096);

    // Mac can't set default value, so we do memset here
    memset(s, -1, 1024);

    while (k) {
        int i;

        // 指向下一个可能的解
        s[k] += 1;

        // 在第k层的解空间中找可行解，judge做剪枝
        // 这里之所以这样写，是为了保持跟下面的规范一样
        //for (int i = f(n, k); i <= g(n, k); i++) {...}
        while (s[k] <= 1 && !judge(s, k, total)) {
            s[k] += 1;
        }

        if (s[k] <= 1) {
            if (k == total) {
                // 找到一个可行解
                char *r = (char *) malloc(sizeof(char) * total);
                for (int j = 1; j <= k; j++) {
                    r[j-1] = ss[s[j]];
                }

                ret[num++] = r;
            } else {
                // 到下一层子数
                k++;
                s[k] = -1;
            }
        } else {
            // 回溯
            k--;
        }
    }

    *returnSize = num;
    return ret;
}
