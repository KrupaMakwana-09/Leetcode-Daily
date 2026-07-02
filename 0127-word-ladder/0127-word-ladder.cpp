class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> s;

        if (beginWord == endWord)
            return 0;

        for (auto i : wordList)
            s.insert(i);

        if (s.find(endWord) == s.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        if (s.find(beginWord) != s.end())
            s.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (temp == endWord)
                        return dist + 1;

                    if (s.find(temp) != s.end()) {
                        q.push({temp, dist + 1});
                        s.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};