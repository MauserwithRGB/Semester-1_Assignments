#include <stdlib.h> // For malloc(), free(), and qsort()

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 1. Create a struct to hold both the value and its original index
struct numWithIndex {
    int val;
    int index;
};

// 2. Create a comparison function for qsort()
//    This tells qsort to sort based on the 'val' field
int compare(const void *a, const void *b) {
    struct numWithIndex *elemA = (struct numWithIndex *)a;
    struct numWithIndex *elemB = (struct numWithIndex *)b;

    // Use long long to prevent overflow during subtraction
    long long diff = (long long)elemA->val - (long long)elemB->val;
    
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

/**
 * Finds two numbers in 'nums' that add up to 'target'.
 * nums: The input array of integers.
 * numsSize: The number of elements in 'nums'.
 * target: The target sum.
 * returnSize: A pointer that will be set to the size of the returned array (which is 2).
 * Returns: A heap-allocated array of 2 integers (the indices), or NULL.
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    // 3. Create and populate the array of structs
    struct numWithIndex* arr = (struct numWithIndex*)malloc(numsSize * sizeof(struct numWithIndex));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    // 4. Sort the array of structs based on 'val'
    //    Time complexity of qsort is O(n log n)
    qsort(arr, numsSize, sizeof(struct numWithIndex), compare);

    // 5. Use the two-pointer technique to find the pair
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        // Use long long for the sum to prevent potential overflow
        long long sum = (long long)arr[left].val + (long long)arr[right].val;

        if (sum == (long long)target) {
            // Found it! Allocate memory for the result array.
            int* result = (int*)malloc(2 * sizeof(int));
            
            // Set the returnSize pointer (as required by the prompt's implied signature)
            *returnSize = 2;
            
            // Store the *original* indices
            result[0] = arr[left].index;
            result[1] = arr[right].index;

            // Free the temporary struct array we created
            free(arr);
            
            return result;
            
        } else if (sum < (long long)target) {
            // Sum is too small, need a larger number
            left++;
        } else { // sum > target
            // Sum is too large, need a smaller number
            right--;
        }
    }

    // No solution found (though the problem guarantees one)
    free(arr);
    *returnSize = 0;
    return NULL;
}
