#include <stdbool.h>

bool isMatch(char* s, char* p) {
    int i = 0; // Pointer for string s
    int j = 0; // Pointer for pattern p
    
    int starIdx = -1; // Tracks the position of the last encountered '*'
    int matchIdx = 0; // Tracks the matched position in s corresponding to starIdx
    
    while (s[i] != '\0') {
        // Case 1: Characters match, or pattern has '?' (matches any single character)
        if (p[j] != '\0' && (p[j] == '?' || p[j] == s[i])) {
            i++;
            j++;
        }
        // Case 2: Pattern has '*', record its position and assume it matches 0 characters first
        else if (p[j] != '\0' && p[j] == '*') {
            starIdx = j;
            matchIdx = i;
            j++; // Advance pattern pointer past '*'
        }
        // Case 3: Mismatch, but a previous '*' was encountered
        // Backtrack: assume the last '*' consumes one more character from string s
        else if (starIdx != -1) {
            j = starIdx + 1; // Reset pattern pointer to right after the '*'
            matchIdx++;      // Advance string match tracker
            i = matchIdx;    // Reset string pointer to the updated match position
        }
        // Case 4: Mismatch and no previous '*' to fall back on
        else {
            return false;
        }
    }
    
    // Check for remaining characters in the pattern; they must all be '*'
    while (p[j] != '\0' && p[j] == '*') {
        j++;
    }
    
    // If we reached the end of the pattern, it is a full match
    return p[j] == '\0';
}
