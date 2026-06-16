class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        vector<int> startIdxs;

        // Run 'len' times to cover all possible character alignments
        for (int idx = 0; idx < len; idx++) {
            int startIdx = idx;

            // Map maps a word to {expected_count, current_count}
            unordered_map<string, pair<int, int>> mp;
            for (auto ss : words) {
                if (mp.count(ss))
                    mp[ss].first++;
                else
                    mp[ss] = {1, 0};
            }
            
            int count = 0; // Tracks how many unique words are fully matched
            for (int i = idx; i < s.size(); i += len) {
                string ss = s.substr(i, len);

                if (mp.count(ss)) {
                    mp[ss].second++;
                    
                    // If we reached the exact needed amount for this word
                    if (mp[ss].second == mp[ss].first)
                        count++;
                        
                    // If we have too many of this word, shrink window from the left
                    while (mp[ss].second > mp[ss].first) {
                        string remove = s.substr(startIdx, len);
                        if (mp[remove].first == mp[remove].second)
                            count--; // We lost a fully matched word
                        mp[remove].second--;
                        startIdx += len;
                    }

                    // If all unique words are matched perfectly
                    if (count == mp.size()) {
                        startIdxs.push_back(startIdx);
                        // Slide window forward by one word to find next potential match
                        string remove = s.substr(startIdx, len);
                        mp[remove].second--;
                        startIdx += len;
                        count--;
                    }
                } else {
                    // Invalid word breaks the sequence, reset the window completely
                    while (startIdx < i + len) {
                        string remove = s.substr(startIdx, len);
                        if (mp.count(remove)) {
                            if (mp[remove].first == mp[remove].second)
                                count--;
                            mp[remove].second--;
                        }
                        startIdx += len;
                    }
                }
            }
        }

        return startIdxs;
    }
};