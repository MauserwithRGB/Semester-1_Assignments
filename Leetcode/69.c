int mySqrt(int x) {
    if (x < 2) return x;

    int left = 1;
    int right = x;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare using division to avoid integer overflow (mid * mid > INT_MAX)
        if (mid == x / mid) {
            return mid;
        } else if (mid < x / mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // When the loop ends, right is the largest integer such that right*right <= x
    return right;
}
