class CountSquares {
private:
    unordered_map<int, unordered_map<int,int>> ptsCount;

public:
    CountSquares() {
    }

    void add(vector<int> point) {
        ptsCount[point[0]][point[1]]++;
        // O(1)
    }

    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0], y1 = point[1];

        for (auto &[y2, count] : ptsCount[x1]){
            // iterate through all points in same x axis
            int side = y2 - y1;
            if (side == 0) continue;

            int x3 = x1 + side, x4 = x1 - side;
            res += count * ptsCount[x3][y1] * ptsCount[x3][y2];
            res += count * ptsCount[x4][y1] * ptsCount[x4][y2];
        }
        return res;
        // O(n)
    }
};