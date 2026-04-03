class Solution {
public:
    int uniquePaths(int m, int n) {
        // now going only row per row instead of saving the entire grid in memory.
        vector<int> row(n, 1);

        for (int i = m-1; i > 0; --i){
            vector<int> newRow(n, 1);
            for (int j = n - 2; j >= 0; --j){
                newRow[j] = newRow[j+1] + row[j];
            }
            row = newRow;
        }

        return row[0];
    }
};
