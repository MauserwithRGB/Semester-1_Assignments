#include <string.h> // For strncpy, strlen
#include <stdlib.h> // For malloc

char* longestCommonPrefix(char** strs, int strsSize) {
    // Edge case: empty array
    if (strsSize == 0) {
        // Allocate and return an empty string
        char* prefix = (char*)malloc(1);
        prefix[0] = '\0';
        return prefix;
    }

    // Iterate through the characters of the first string
    for (int i = 0; ; i++) {
        char c;
        
        // Check if we've reached the end of the first string
        if (strs[0][i] == '\0') {
            c = '\0'; // Use null char as the signal
        } else {
            c = strs[0][i];
        }

        // Check this character against all other strings
        for (int j = 1; j < strsSize; j++) {
            // If the other string is shorter OR the character doesn't match
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                // The prefix is from strs[0] up to (but not including) index i
                // 'i' is the length of the common prefix
                char* prefix = (char*)malloc(i + 1);
                strncpy(prefix, strs[0], i);
                prefix[i] = '\0';
                return prefix;
            }
        }
        
        // If the character was the null terminator, it means all strings
        // matched up to the end of the first string.
        if (c == '\0') {
            // The entire first string is the prefix.
            // 'i' is its length.
            char* prefix = (char*)malloc(i + 1);
            strncpy(prefix, strs[0], i);
            prefix[i] = '\0';
            return prefix;
        }
    }
}
