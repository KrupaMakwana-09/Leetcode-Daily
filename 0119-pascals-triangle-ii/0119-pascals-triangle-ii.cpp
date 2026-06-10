class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> temp(rowIndex + 1, vector<int>(rowIndex + 1, 1));
        for(int i = 0; i < temp.size(); i++){
            for(int j = 0; j < i+1; j++){
                if(i > 1 && j != 0 && j != i){
                    temp[i][j] = temp[i-1][j-1] + temp[i-1][j];
                }
            }
        }
        return temp[rowIndex];
    }
};