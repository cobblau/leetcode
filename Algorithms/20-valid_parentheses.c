/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */
#define DEBUG 0
/*
Description:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#if DEBUG
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#endif

bool isValid(char* s) {
    int len = strlen(s);
    char *p, cur;
    char *stack = (char *) malloc(sizeof(char) * len);
    int top = 0;

    if (len == 0) {
        return true;
    }

    p = s;
    stack[top++] = *p++;
    while (p < s + len) {
        cur = stack[top-1];

        switch (*p) {
        case '(':
        case '[':
        case '{':
            stack[top++] = *p++;
            break;
        case ')':
            if (cur != '(') {
                return false;
            }
            top--;
            p++;
            break;
        case ']':
            if (cur != '[') {
                return false;
            }
            top--;
            p++;
            break;
        case '}':
            if (cur != '{') {
                return false;
            }
            top--;
            p++;
            break;
        }
    }

    if (top == 0) {
        return true;
    }

    return false;
}

#if DEBUG
int main() {
    printf("%d\n", isValid("()"));
    printf("%d\n", isValid("()[]"));
    printf("%d\n", isValid("()[]{}"));
    printf("%d\n", isValid("(([]))"));
    printf("%d\n", isValid("(())(]"));
}
#enfif
