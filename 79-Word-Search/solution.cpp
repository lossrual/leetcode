class Solution {
public:
//搜索单词,广搜
    bool exist(vector<vector<char>>& board, string& word) {
        //int dir[][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(helper(board, word, visited, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string word, vector<vector<bool>>& used, int index, int x, int y){
        if(index == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        if(used[x][y]) return false;
        if(board[x][y] != word[index]) return false;
        used[x][y] = true;
        bool res = helper(board, word, used, index + 1, x + 1, y) || 
                    helper(board, word, used, index + 1, x - 1, y) ||
                    helper(board, word, used, index + 1, x, y + 1) ||
                    helper(board, word, used, index + 1, x, y - 1);
        used[x][y] = false;
        return res;
    }
     bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int index, int x, int y){
        if(index == word.size()) return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if(visited[x][y]) return false;
        if(board[x][y] != word[index]) return false;
        visited[x][y] = true;
        bool res = dfs(board, word, visited, index + 1, x - 1, y) || 
        dfs(board, word, visited, index + 1, x + 1, y) ||
        dfs(board, word, visited, index + 1, x, y - 1) ||
        dfs(board, word, visited, index + 1, x, y + 1);
        visited[x][y] =false;
        return res;
    }
};