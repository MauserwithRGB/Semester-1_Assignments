int climbStairs(int n) {
    if (n <= 2) return n;
    
    int prev1 = 2; // Ways to reach step n-1
    int prev2 = 1; // Ways to reach step n-2
    int current = 0;
    
    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}
