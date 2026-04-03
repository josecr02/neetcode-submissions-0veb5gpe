class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // Dijkstra, O(n2logn)
        // we keep the max time needed as the cost to reach each node.
        int n = grid.size();
        set<pair<int, int>> visit; // when we see a neighbour, we add it to the visited set.
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        minHeap.push({grid[0][0], 0, 0}); // start at 0,0.
        visit.insert({0, 0});

        while (!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int t = curr[0], row = curr[1], column = curr[2];
            if (row == n - 1 && column == n - 1){
                // means we reached bottom right.
                // so we return the current max height we have seen.
                return t;
            }
            for (const auto& dir : directions){
                int neiR = row + dir[0], neiC = column + dir[1];
                if (neiR < 0 || neiR == n || neiC < 0 || neiC == n || visit.count({neiR, neiC})){
                    continue;
                }
                visit.insert({neiR, neiC});
                minHeap.push({max(t, grid[neiR][neiC]), neiR, neiC});

            }
        }

        // in this case we have not reached the bottom right, we just return anything.
        return -1;
    }
};
