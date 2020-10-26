int solve(vector<int>& nums, int k) {
    int n = nums.size(); 
    if (n == 0) return 0; 
    int mod = 1e9 + 7;
    // dp1[i] - #valid sublists ending at i
    // dp2[i] - #valid sublists starting at i
    vector<long long> dp1(n), dp2(n);  
    
    dp1[0] = nums[0] >= k; 
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] >= k) dp1[i] = dp1[i - 1] + 1; 
    }
    dp2[n - 1] = nums[n - 1] >= k; 
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] >= k) dp2[i] = dp2[i + 1] + 1; 
    }
    // dp2[i] - #valid sublists starting at >= i
    for (int i = n - 2; i >= 0; i--) 
        dp2[i] = (dp2[i] + dp2[i + 1]) % mod; 
    
    long long ans = 0; 
    for (int i = 0; i < n - 1; i++)
    {
        ans = (ans + dp1[i] * dp2[i + 1]) % mod; 
    }
    return ans; 
}
