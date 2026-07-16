class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // We need a 3-element vector to do the rolling array logic safely
        vector<int> dp(3, 0);

        // --->> FIRST PASS: Houses 0 to n-2 (Skip the last house) ---
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        // Start from index 2 and go up to and INCLUDING n-2
        for (int i = 2; i < n - 1; i++) {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(nums[i] + dp[0], dp[1]);
        }
        int result = dp[2];

        // --->> SECOND PASS: Houses 1 to n-1 (Skip the first house) ---
        // Initialize based strictly on indices 1 and 2
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);

        // Start from index 3 and go up to and INCLUDING n-1
        for (int i = 3; i < n; i++) {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(nums[i] + dp[0], dp[1]);
        }

        result = max(result, dp[2]);

        return result;
    }
};