class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> vs = getTri(rowIndex + 1);
        return vs[vs.size() - 1];
    }
    vector<vector<int>> getTri(int numRows){
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; i++){
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
            for(int j = 1; j < i; j++){
                res[i][j] = res[i - 1][j - 1] + res[i- 1][j];
            }
        }
        return res;
    }
};