class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int prefix = 0;
        int suffix = accumulate(nums.begin(), nums.end(), 0);
        vector<int> res;
        for (int i : nums) {
            prefix += i;
            res.push_back(abs(prefix - suffix));
            suffix -= i;
        }
        return res;
    }
};