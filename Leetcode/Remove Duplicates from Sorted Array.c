int removeDuplicates(int* nums, int numsSize) {
    // If the array is empty, there are no unique elements.
    if (numsSize == 0) {
        return 0;
    }
    
    // 'k' is the "write pointer". It tracks the index of the
    // last unique element found. We start at index 0, as the
    // first element is always unique by default.
    int k = 0;
    
    // 'i' is the "read pointer". We start at the second element (index 1)
    // to compare it with the one at 'k'.
    for (int i = 1; i < numsSize; i++) {
        
        // If the "read" element is different from the last "written" element...
        if (nums[i] != nums[k]) {
            // ...it's a new unique element.
            
            // 1. Move the "write" pointer to the next slot.
            k++;
            
            // 2. Write the new unique element to that slot.
            nums[k] = nums[i];
        }
        // If nums[i] == nums[k], it's a duplicate. We just
        // let 'i' advance, effectively skipping this element.
    }
    
    // The unique elements are stored from index 0 to k.
    // The total *count* of unique elements is k + 1.
    return k + 1;
}
