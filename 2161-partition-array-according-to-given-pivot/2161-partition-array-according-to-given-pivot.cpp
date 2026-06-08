class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot);

        int smallerCount = 0, greaterCount = 0;

        for (int num : nums) {
            if (num < pivot) smallerCount++;
            if (num > pivot) greaterCount++;
        }

        int sp = 0;
        int gp = n - greaterCount;

        for (int num : nums) {
            if (num < pivot) ans[sp++] = num;
            if (num > pivot) ans[gp++] = num;
        }

        return ans;
    }
};