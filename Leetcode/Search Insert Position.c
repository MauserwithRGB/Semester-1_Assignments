int searchInsert(int* nums, int numsSize, int target) {
    // Initialize pointers for the start and end of the array
    int left = 0;
    int right = numsSize - 1;
    
    // Loop while the search space is valid (left <= right)
    while (left <= right) {
        // Calculate mid-point, avoiding potential integer overflow
        int mid = left + (right - left) / 2;
        
        // Check the middle element
        if (nums[mid] == target) {
            // Target found!
            return mid;
        } else if (nums[mid] < target) {
            // Target is in the right half
            left = mid + 1;
        } else {
            // Target is in the left half
            right = mid - 1;
        }
    }
    
    // Loop finished, target was not found.
    // 'left' is now the index where the target would be inserted.
    return left;
}
