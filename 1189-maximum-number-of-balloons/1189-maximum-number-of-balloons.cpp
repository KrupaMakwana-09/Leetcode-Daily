class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = INT_MAX;
        map<char, int> mp;

        for(auto & it : text) {
            mp[it]++;
        }
        for(auto & it : mp) {
            if(it.first == 'a') {
                ans = min(ans, it.second);
            }
            if(it.first == 'b' && ans != INT_MAX) ans = min(ans, it.second);
            if(it.first == 'l' && ans != INT_MAX) ans = min(ans, it.second / 2);
            if(it.first == 'n' && ans != INT_MAX) ans = min(ans, it.second);
            if(it.first == 'o' && ans != INT_MAX) ans = min(ans, it.second / 2);
        }
        return ans != INT_MAX ? ans : 0;
    }
};