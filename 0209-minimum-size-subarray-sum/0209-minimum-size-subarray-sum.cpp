class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minVal = INT_MAX;
        int l = 0;
        int sum = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum >= target) {
                minVal = min(minVal, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        if (minVal == INT_MAX) {
            return 0;
        }

        return minVal;
    }
};