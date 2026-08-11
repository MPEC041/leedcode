class Solution {
public:
    int totalPaths = 0;
    int emptyCells = 0;

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX = 0, startY = 0;
        int m = grid.size();
        int n = grid[0].size();

        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 0) {
                    emptyCells++; 
                }
            }
        }

       
        dfs(grid, startX, startY, 0);
        return totalPaths;
    }

private:
    void dfs(vector<vector<int>>& grid, int x, int y, int stepsWalked) {
        int m = grid.size();
        int n = grid[0].size();

       
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1) {
            return;
        }

       
        if (grid[x][y] == 2) {
            if (stepsWalked == emptyCells + 1) {
                totalPaths++;
            }
            return;
        }

        
        int originalValue = grid[x][y];
        grid[x][y] = -1;

        // Explore 4 directions
        dfs(grid, x + 1, y, stepsWalked + 1);
        dfs(grid, x - 1, y, stepsWalked + 1); 
        dfs(grid, x, y + 1, stepsWalked + 1); 
        dfs(grid, x, y - 1, stepsWalked + 1); 
        grid[x][y] = originalValue;
    }
};
