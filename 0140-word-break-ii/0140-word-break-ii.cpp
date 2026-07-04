class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    int n;

    void solver(int idx, string& s, string& currStr) {
        if (idx >= n) {
            ans.push_back(currStr);
            return;
        }

        for (int i = idx; i < n; i++) {
            string tempWord = s.substr(idx, i - idx + 1);
            if (st.count(
                    tempWord)) { // we have found a valid word from dictionary

                string storeOriginal = currStr;
                currStr = currStr.empty() ? tempWord : currStr + " " + tempWord;
                solver(i + 1, s, currStr);
                currStr = storeOriginal;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto& i : wordDict) {
            st.insert(i);
        }
        n = s.size();
        string curStr = "";

        solver(0, s, curStr); // index,string, currentString

        return ans;
    }
};