class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;

        // If string is too short, no repeated sequence possible
        if(n <= 10) return ans;

        // Store frequency of both hashes
        unordered_map<long long,int> seen1, seen2;

        // Two different mod values for safety against collision
        long long MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;

        // Two different bases
        long long B1 = 131, B2 = 31;

        // Highest power for sliding window removal
        long long pow1 = 1, pow2 = 1;

        // Current rolling hash values
        long long h1 = 0, h2 = 0;

        // Build initial hash for first 10 characters
        for(int i = 0; i < 10; i++){
            if(i){
                pow1 = pow1 * B1 % MOD1;
                pow2 = pow2 * B2 % MOD2;
            }
            h1 = (h1 * B1 + s[i]) % MOD1;
            h2 = (h2 * B2 + s[i]) % MOD2;
        }

        // Slide window across the string
        for(int i = 0; i <= n - 10; i++){
            seen1[h1]++;
            seen2[h2]++;

            // Add only when both hashes appear second time
            if(seen1[h1] == 2 && seen2[h2] == 2)
                ans.push_back(s.substr(i,10));

            // Remove left char and add next char (rolling update)
            if(i < n - 10){
                h1 = ((h1 - s[i] * pow1 % MOD1 + MOD1) * B1 + s[i+10]) % MOD1;
                h2 = ((h2 - s[i] * pow2 % MOD2 + MOD2) * B2 + s[i+10]) % MOD2;
            }
        }
        return ans;
    }
};