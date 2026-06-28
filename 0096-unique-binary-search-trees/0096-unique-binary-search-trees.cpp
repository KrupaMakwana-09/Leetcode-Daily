class Solution {
public:
    int numTrees(int n) {
        long long x = 1, ans;
        for(int i = 1; i <= n; i++){
            x = x *(i + n) / i;
        }
        ans = x / (n+1);
        return ans;
    }
};