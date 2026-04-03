class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        vector<int> steps = {matrix[0].size(), matrix.size() - 1};

        int r = 0, c = -1, d = 0;
        while (steps[d%2]){ // we use d%2 because we map the direction to the number of steps remaining
        // horizontally or vertucally.
            for (int i = 0; i < steps[d%2]; ++i){
                r += directions[d].first; // ad row and column
                c += directions[d].second;
                res.push_back(matrix[r][c]);
            }
            steps[d%2]--;
            d= (d + 1) % 4; // update direction to be right, down, left, up.
        }
        return res;
    }
};
