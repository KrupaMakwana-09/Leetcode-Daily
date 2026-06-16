class Solution {
public:
    string processStr(string s)
    {
        //time complexity: O(n)
        //space complexity: O(n)

        // Stores the final processed string
        string ans = "";

        // Traverse each character
        for(char ch : s)
        {
            // Remove last character
            if((ch == '*') && (ans.size() >= 1))
                ans.pop_back();

            // Duplicate current string
            else if((ch == '#') && (ans.size() >= 1))
            {
                // Store current string
                string temp = ans;

                // Append duplicate
                ans += temp;
            }

            // Reverse current string
            else if(ch == '%')
                reverse(ans.begin(), ans.end());

            // Append lowercase letters
            if((ch >= 'a') && (ch <= 'z'))
                ans += ch;
        }

        // Return final result
        return ans;
    }
};