class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // sounds like multi source bfs. bfs uses queue.
        // it's like shortest distances from any of the rotten fruits.

        // we start all bfs together

        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;

        for (int r = 0; r < grid.size(); ++r){
            for (int c = 0; c < grid[0].size(); ++c){
                if (grid[r][c] == 1){
                    ++fresh;
                }
                else if (grid[r][c] == 2){
                    q.push({r, c});
                }
            }

        }

        vector<pair<int,int>> directions{{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty() && fresh > 0){
            int length = q.size(); // number of rotten fruit sources
            for (int i = 0; i < length; ++i){ // pop sources
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for (const auto& dir : directions){
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row, col});
                        --fresh;
                    }
                }
            }
            ++time;
        }
        return fresh == 0 ? time : -1;
    }
};
