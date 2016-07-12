class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int a = 0, b = n - 1;
        while(a <= m - 1 && b >= 0){
            if(target < matrix[a][b]) b--;
            else if(target > matrix[a][b]) a++;
            else{
                return true;
            }
        }
        return false;
    }
};