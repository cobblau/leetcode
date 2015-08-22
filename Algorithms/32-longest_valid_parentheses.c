/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */

#define DEBUG 0

/*
Description:

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#if DEBUG
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#endif

int longestValidParentheses(char* s) {
    int len = strlen(s);
    int max = 0;

    int *stack = (int *) malloc(sizeof(int) * len);
    int top = 0, cur = -1;

    if (len == 0) {
        return 0;
    }

    stack[top++] = cur;
    for (int i = 0; i < len; i++) {
        cur = stack[top-1];
        if (cur != -1 && s[i] == ')' && s[cur] == '(') {
            top--;
            int l = i - stack[top-1];
            max = max > l ? max : l;
            continue;
        }

        stack[top++] = i;
    }

    return max;
}

#if DEBUG
int main() {
    printf("%d\n", longestValidParentheses("()"));
    printf("%d\n", longestValidParentheses("()()"));
    printf("%d\n", longestValidParentheses("()()()"));
    printf("%d\n", longestValidParentheses("()(()"));
}
#endif
