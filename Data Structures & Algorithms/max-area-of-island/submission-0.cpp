class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // an island is connected horizontally or vertically. we can do dfs/bfs
        // area is number of cells.
        // BFS
        // we mark an island as 0 to denote as seen.
        // O(nm), the bfs algo is O(n + m).
        int ROWS = grid.size(), COLS = grid[0].size();
        int area = 0;

        for (int r = 0; r < ROWS; ++r){
            for (int c= 0; c < COLS; ++c){
                if (grid[r][c] == 1){
                    area = max(area, bfs(grid, r, c));
                }
            }
        }

        return area;
    }

    int bfs(vector<vector<int>>& grid, int r, int c){
        queue<pair<int,int>> q;
        grid[r][c] = 0;
        q.push({r, c});
        int res = 1;

        while (!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            for (int i = 0; i < 4; ++i){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                    ++res;
                }
            }
        }

        return res;
    }
};
