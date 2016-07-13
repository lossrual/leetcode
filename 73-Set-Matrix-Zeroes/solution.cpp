class Solution {
public:
    //space:O(m+n),设置一个备忘录
    void setZeroes1(vector<vector<int>>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < m; i++){
            if(row[i]){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(col[j]){
                for(int i = 0; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix){
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool row_has_zero = false;
        bool col_has_zero = false;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){ 
                row_has_zero = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0) {
                col_has_zero = true;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(row_has_zero){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        if(col_has_zero){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
    }
    
    
    
    
    //O(1) 设置第一行第一列带有0,之后的复制,意思就是所有的0都集中在第一行第一列上
    void setZeroes2(vector<vector<int>>& matrix){
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool row_has_zero = false;
        bool col_has_zero = false;
        //第一列
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0) row_has_zero = true;
        }
        //第一行
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0) col_has_zero = true;
        }
        //当中有的话也转移到第一列和第一行
        for(int i = 1; i < m ; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //先处理当中的
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        //在处理第一行的
        if (row_has_zero){ 
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;    
        }
        }
        //处理第一列的
        if (col_has_zero){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
    }   
    
    
    
};



