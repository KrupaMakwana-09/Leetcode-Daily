class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        queue<int> q; q.push(0);
        vector<bool> vis(n + 1, false); vis[0] = true;

        auto check_match = [&](int start, string& t) -> bool {
            int k = t.size();
            
            int index = 0;
            while (index < k && t[index] == s[index + start])
                index++;
            
            return index == k;
        };

        while (!q.empty()) {
            auto start_pos = q.front(); q.pop();
            
            if (start_pos == n)
                return true;

            for (auto& wi : wordDict) {
                int k = wi.size();
                if (start_pos + k > n) 
                    continue;
                
                bool is_match = check_match(start_pos, wi);

                if (is_match) {
                    int end = start_pos + k;

                    if (end <= n && !vis[end]) {
                        q.push(end);
                        vis[end] = true;
                    }
                }
            }
        }

        return false;
    }
};