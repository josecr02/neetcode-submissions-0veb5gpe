class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int res = 0;

        for (int i = 0; i < ROWS; ++i){
            for (int j = 0; j < COLS; ++j){
                if (grid[i][j] == '1'){
                    ++res;
                    bfs(grid, ROWS, COLS, i, j);
                }
            }
        }

        return res;
    }

    void bfs(vector<vector<char>>& grid, int ROWS, int COLS, int r, int c){
        queue<pair<int,int>> q; // r,c
        q.push({r, c});

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            grid[i][j] = '0';
            for (auto dir : directions){
                int nr = i + dir[0];
                int nc = j + dir[1];
                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                }
            }
        }
    }
};
