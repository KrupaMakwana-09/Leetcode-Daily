class Solution {
public:
    int calculate(string s) {

        stack<int> st;
        int num = 0;
        char prev = '+';

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (isdigit(ch))
                num = num * 10 + (ch - '0');

            if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1) {

                if (prev == '+')
                    st.push(num);

                else if (prev == '-')
                    st.push(-num);

                else if (prev == '*') {
                    int val = st.top();
                    st.pop();
                    st.push(val * num);
                }

                else if (prev == '/') {
                    int val = st.top();
                    st.pop();
                    st.push(val / num);
                }

                prev = ch;
                num = 0;
            }
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};