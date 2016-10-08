class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ++res;
                    //bfs(grid, i, j);
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<vector<int>> que;
        que.push({i, j});
        //if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        //if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        while(!que.empty()){
            i = que.front()[0]; j = que.front()[1];
            que.pop();
            if(i - 1 >= 0 && grid[i - 1][j] == '1'){
                que.push({i - 1, j});
                grid[i - 1][j] = '0';
            }
            if(i +1 < grid.size() && grid[i + 1][j] == '1'){
                que.push({i + 1, j});
                grid[i + 1][j] = '0';
            }
            if(j - 1 >= 0 && grid[i][j - 1] == '1'){
                que.push({i, j - 1});
                grid[i][j - 1] = '0';
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == '1'){
                que.push({i, j + 1});
                grid[i][j + 1] = '0';
            }
        }
    }
};