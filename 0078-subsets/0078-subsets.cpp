class Solution 
{
    public:
        void solve(vector<vector<int>> &ans, vector<int>& nums, int cnt, vector<int> subset)
        {
            if(cnt==nums.size())   //traversed all elements
            {
                ans.push_back(subset);
                return;
            }
            
            solve(ans,nums,cnt+1,subset);   //choice 1: don't push current element
            
            subset.push_back(nums[cnt]);    //choice 2: push current element
            solve(ans,nums,cnt+1,subset);      
        }
    
        vector<vector<int>> subsets(vector<int>& nums) 
        {
            vector<vector<int>> ans;
            solve(ans,nums,0,{});
            return ans;
        }
};