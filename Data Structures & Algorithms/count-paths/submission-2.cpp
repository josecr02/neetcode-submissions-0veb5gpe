class Solution {
public:
    int uniquePaths(int m, int n) {
        // now going only row per row instead of saving the entire grid in memory.
        vector<int> row(n, 1);

        for (int i = m-1; i > 0; --i){
            for (int j = n - 2; j >= 0; --j){
                row[j] += row[j+1];
            }
        }

        return row[0];
    }
};
