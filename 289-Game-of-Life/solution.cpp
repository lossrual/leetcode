class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int dir[][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(x < 0 || x >= m || y < 0 || y >= n) continue;
                    if(board[x][y] & 0x1) cnt++;
                }
                if(board[i][j] == 0){
                    if(cnt == 3) board[i][j] = 2;
                }else{
                    if(cnt < 2 || cnt > 3) board[i][j] = 1;
                    else board[i][j] = 3;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] >>= 1;
            }
        }
        
    }
};