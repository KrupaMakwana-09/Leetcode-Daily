#include <limits.h>

int myAtoi(char *s) {
    int i = 0;
    int sign = 1;
    long long num = 0;

    // Skip leading spaces
    while (s[i] == ' ') {
        i++;
    }

    // Check sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // Convert digits
    while (s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');

        // Handle overflow
        if (sign * num > INT_MAX) {
            return INT_MAX;
        }
        if (sign * num < INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    return (int)(sign * num);
}