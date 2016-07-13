class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        if(m <= 0 || n <= 0) return res;
        int x0 = 0, x1 = m - 1, y0 = 0, y1 = n - 1;
        while(x0 <= x1 && y0 <= y1){
            for(int i = y0; i <= y1; i++)
                res.push_back(matrix[x0][i]);
            x0++;
            for(int i = x0; i <= x1; i++)
                res.push_back(matrix[i][y1]);
            y1--;
            if(x0 > x1) break;
            for(int i = y1; i >= y0; i--)
                res.push_back(matrix[x1][i]);
            x1--;
            if(y1 < y0) break;
            for(int i = x1; i >= x0; i--)
                res.push_back(matrix[i][y0]);
            y0++;
        }
        return res;
    }
};