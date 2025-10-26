class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, int empty,
             int& totalpath) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
            grid[x][y] ==-1)
            return;
        if (grid[x][y] == 2) {
            if (empty == -1)
                totalpath++;
            return;
        }
        grid[x][y] = -1;
        dfs(grid, x + 1, y, empty - 1, totalpath);
        dfs(grid, x - 1, y, empty - 1, totalpath);
        dfs(grid, x, y + 1, empty - 1, totalpath);
        dfs(grid, x, y - 1, empty - 1, totalpath);
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size();
        int empty = 0;
        int startX;
        int startY;
        int totalpath = 0;
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0)
                    empty++;

                else if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        dfs(grid, startX, startY, empty, totalpath);
        return totalpath;
    }
};