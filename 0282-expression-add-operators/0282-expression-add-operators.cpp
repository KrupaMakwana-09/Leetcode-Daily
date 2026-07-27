class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(res, num, target, 0, "", 0, 0);
        return res;
    }

    void backtrack(vector<string>& res, string& num, int target, int idx, string expr, long long currVal, long long prev){
        if(idx == num.size()){
            if(currVal == target) res.push_back(expr);
            return;
        }

        for(int j = idx; j < num.size(); j++){
            if(j > idx && num[idx] == '0') break;

            string part = num.substr(idx, j - idx + 1);
            long long n = stoll(part);

            if(idx == 0){
                backtrack(res, num, target, j + 1, part, n, n);
            }
            else{
                backtrack(res, num, target, j + 1, expr + "+" + part, currVal + n, n);

                backtrack(res, num, target, j + 1, expr + "-" + part, currVal - n, -n);

                backtrack(res, num, target, j + 1, expr + "*" + part, currVal - prev + prev * n, prev * n);
            }
        }
    }
};