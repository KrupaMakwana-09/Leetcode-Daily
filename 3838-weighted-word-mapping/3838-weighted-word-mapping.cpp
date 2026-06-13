class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        
        for (int i = 0; i < words.size(); i++) {
            int wordSum = 0;
            
            // Calculate the sum of weights for the current word
            for (int j = 0; j < words[i].size(); j++) {
                wordSum += weights[words[i][j] - 'a'];
            }

            // The Math: 'a' is 97. We calculate the reverse offset directly.
            ans += 97 + (26 - (wordSum % 26) - 1);
        }
        
        return ans;
    }
};