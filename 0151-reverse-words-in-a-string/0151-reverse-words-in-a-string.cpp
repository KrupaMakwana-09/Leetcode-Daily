class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, k = 0, n = s.size();
        while (i < n) {
            // Find the starting pos of the next word
            while (i < n && s[i] == ' ') i++;

            if (i != n && k > 0) { // Still have the next word, add " " here
                s[k++] = ' ';
            }

            int start_index = k;
            // Find the ending pos of that word
            while (i < n && s[i] != ' ') s[k++] = s[i++];

            // Reverse that word
            reverse(s.begin() + start_index, s.begin() + k);
        }
        s.resize(k);
        return s;
    }
};