#include <string.h> // Required for strlen()

int strStr(char* haystack, char* needle) {
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    // We only need to check starting positions in 'haystack'
    // up to the point where 'needle' can still fit.
    //
    // If needleLen > haystackLen, (haystackLen - needleLen) will be
    // negative, and this loop will not run (i=0 is not <= negative),
    // correctly leading to a 'return -1' at the end.
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        
        int j;
        // Try to match the entire 'needle' string
        for (j = 0; j < needleLen; j++) {
            // Compare the char in haystack's "window" with the char in needle
            if (haystack[i + j] != needle[j]) {
                // Mismatch found, break this inner loop
                // and try the next 'i'
                break;
            }
        }
        
        // If the inner loop 'j' completed without breaking,
        // it means j is equal to needleLen.
        // This signifies a full match.
        if (j == needleLen) {
            return i; // Found the first occurrence!
        }
    }
    
    // If we get through the whole outer loop, no match was found.
    return -1;
}
