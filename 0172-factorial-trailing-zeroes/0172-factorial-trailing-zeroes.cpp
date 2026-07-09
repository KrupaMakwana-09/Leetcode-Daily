class Solution {
public:
    int trailingZeroes(int n) {
        return (n/5) + (n/(5*5)) + (n/(5*5*5)) + (n/(5*5*5*5)) + (n/(5*5*5*5*5));
    }
};