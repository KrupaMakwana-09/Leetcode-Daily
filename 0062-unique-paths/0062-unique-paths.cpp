class Solution {
public:
    int solver(int& m, int& n, int i, int j) {
        if (i == m - 1 && j == n - 1)
            return 1;
        else if (i >= m || j >= n)
            return 0;
        int right = 0, bottom = 0;
        if (j + 1 < n)
            right = solver(m, n, i, j + 1);
        if (i + 1 < m)
            bottom = solver(m, n, i + 1, j);
        return right + bottom;
    }
    int solverMem(int& m, int& n, int i, int j, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1)
            return 1;
        else if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = 0, bottom = 0;
        if (j + 1 < n)
            right = solverMem(m, n, i, j + 1, dp);
        if (i + 1 < m)
            bottom = solverMem(m, n, i + 1, j, dp);
        return dp[i][j] = right + bottom;
    }
    int solverTab(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;
                int right = 0, bottom = 0;
                if (j + 1 < n)
                    right = dp[i][j + 1];
                if (i + 1 < m)
                    bottom = dp[i + 1][j];
                dp[i][j] = right + bottom;
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
       
        return solverTab(m, n);
    }
};