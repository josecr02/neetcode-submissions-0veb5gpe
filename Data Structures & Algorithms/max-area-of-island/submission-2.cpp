class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int res = 0;

        for (int r = 0; r < ROWS; ++r){
            for (int c = 0; c < COLS; ++c){
                if (grid[r][c] == 1){
                    res = max(res, bfs(grid, r, c, ROWS, COLS));
                }
            }
        }

        return res;
    }

private:
    int bfs(vector<vector<int>>& grid, int r, int c, int ROWS, int COLS){
        queue<pair<int,int>> q;
        q.push({r, c});
        int res = 0;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            ++res;
            grid[i][j] = 0;
            for (auto dir : directions){
                int nr = i + dir[0];
                int nc = j + dir[1];
                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    grid[nr][nc] = 0; // important to not repeat
                }
            }
        }

        return res;
    }
};
