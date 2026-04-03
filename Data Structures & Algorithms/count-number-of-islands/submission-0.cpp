class Solution {
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;

        for (int i = 0; i < ROWS; ++i){
            for (int j = 0; j < COLS; ++j){
                if (grid[i][j] == '1'){
                    bfs(grid, i, j);
                    ++islands;
                }
            }
        }

        return islands;
    }

    void bfs(vector<vector<char>>& grid, int r, int c){
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int,int>> q;
        grid[r][c] = '0';
        q.push({r, c});

        while (!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first, col = node.second;
            for (int  i = 0; i < 4; ++i){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
