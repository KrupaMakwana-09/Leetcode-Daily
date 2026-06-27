class Solution {
public:
    int numDecodings(string s) {
        // Base case: empty string or starts with invalid '0'
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int n = s.length();
        
        // dp[i] stores the number of decodings for a string of length i
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            
            // Extract the single digit and two-digit combinations
            int d = s[i - 1] - '0';
            int dd = (s[i - 2] - '0') * 10 + d;

            // Single digit decode (1 step back)
            if (d != 0) {
                dp[i] += dp[i - 1];
            }

            // Two digit decode (2 steps back)
            if (10 <= dd && dd <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};