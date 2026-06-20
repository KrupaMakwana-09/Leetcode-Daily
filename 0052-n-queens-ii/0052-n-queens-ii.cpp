int N;
static bool col[9] = {false}, diag[17] = {false}, adiag[17] = {false};
class Solution {
private:
    inline int dfs(int i){
        if(i == N) return 1;
        int cnt = 0;
        for(int j = 0; j < N; ++j){
            if(col[j] || diag[i + N - j - 1] || adiag[i + j]) continue;
            col[j] = diag[i + N - j - 1] = adiag[i + j] = true;
            cnt += dfs(i + 1);
            col[j] = diag[i + N - j - 1] = adiag[i + j] = false;
        }
        return cnt;
    }
public:
    int totalNQueens(int n) {
        if(n == 1) return 1;
        if(n < 4) return 0;
        N = n;
        return dfs(0);
    }
};