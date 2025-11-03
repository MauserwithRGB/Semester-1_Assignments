void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;      // Last valid element in nums1
    int p2 = n - 1;      // Last element in nums2
    int p = m + n - 1;   // Last position in nums1 buffer

    // Compare and place the larger element at the end of nums1
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p--] = nums1[p1--];
        } else {
            nums1[p--] = nums2[p2--];
        }
    }

    // If nums2 still has elements left, copy them
    // (If nums1 has elements left, they are already in place)
    while (p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }
}
