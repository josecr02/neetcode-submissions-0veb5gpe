class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Dijkstra's.
        // treat it as a graph, where weightes is edge effort.
        // we want min distance path to bottom right.
        // expand min distance.

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = heights.size(), cols = heights[0].size();
        minHeap.push({0, 0, 0}); // {diff, row, col}
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        while (!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int diff = curr[0], r = curr[1], c = curr[2];
            if (r == rows - 1 && c == cols - 1){
                return diff; // max effort along the path, which is the minimum of all possible.
            }
            if (dist[r][c] < diff) continue; // not explore since not optimal
            for (auto& dir : directions){
                int nr = r + dir[0], nc = c + dir[1];
                if (!(nr >= 0 && nr < rows && nc >= 0 && nc < cols)){
                    continue;
                }
                // now we check if the new weight is the maximum along this path
                int newDiff = max(diff, abs(heights[nr][nc] - heights[r][c]));
                if (newDiff < dist[nr][nc]){
                    // then use!
                    dist[nr][nc] = newDiff; // push next
                    minHeap.push({newDiff, nr, nc});
                }
            }
        }

        return 0;
    }
};