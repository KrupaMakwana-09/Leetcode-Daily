class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0]; //that means there is only one house to rob
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1){
                pick = pick+dp[i-2];
            }
            int notPick = dp[i-1];
            dp[i]= max(pick,notPick);
        }
        return dp[n-1];
    }
};