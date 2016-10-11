class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1'){
                    ++res;
                    helper(grid, i, j);
                }
        return res;
    }
    bool invalid(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return true;
        else
            return false;
    }
    void helper(vector<vector<char>>& grid, int x, int y) {
        if(invalid(grid, x, y)) return;
        if(grid[x][y] == '0') return;
        grid[x][y] = '0';
        helper(grid, x + 1, y);
        helper(grid, x - 1, y);
        helper(grid, x, y + 1);
        helper(grid, x, y - 1);
    }
};