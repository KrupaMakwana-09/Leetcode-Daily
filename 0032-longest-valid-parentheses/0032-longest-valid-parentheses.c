#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    // Create a stack large enough to hold indices
    int* stack = (int*)malloc(sizeof(int) * (n + 1));
    int top = -1;

    // Base condition for stack: push -1 to help calculate base lengths
    stack[++top] = -1;

    int max_len = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            // Push the index of the opening bracket
            stack[++top] = i;
        } else {
            // Pop the last matching base/bracket
            top--;

            if (top == -1) {
                // If stack is empty, push current index as the new base
                stack[++top] = i;
            } else {
                // Calculate current valid length
                int current_len = i - stack[top];
                if (current_len > max_len) {
                    max_len = current_len;
                }
            }
        }
    }

    free(stack);
    return max_len;
}
