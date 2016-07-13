class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if (n == 0) return matrix;
        int x1 =n - 1;
        int y1 = n - 1;
        int x0 = 0;
        int y0 =0;
        int num = 1;
        while(x0 <= x1 && y0 <= y1){
            for(int j = y0; j <= y1; j++){
                matrix[x0][j] = num++;
            }
            x0++;
            for(int i = x0; i <= x1; i++) {matrix[i][y1] = num++;}
            y1--;
            if(x0 > x1) break;
            for(int j = y1; j >= y0; j--) {matrix[x1][j] = num++;}
            x1--;
            if(y0 > y1) break;
            for(int i = x1; i >= x0; i--) {matrix[i][y0] = num++;}
            y0++;
        }
        return matrix;
    }
};