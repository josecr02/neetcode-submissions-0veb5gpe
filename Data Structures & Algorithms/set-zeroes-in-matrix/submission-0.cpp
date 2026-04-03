class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<bool> rowZero(rows, false);
        vector<bool> colZero(cols, false);

        for (int r = 0; r < rows; ++r){
            for (int c = 0; c < cols; ++c){
                if (matrix[r][c] == 0){
                    rowZero[r] = true;
                    colZero[c] = true;
                }
            }
        }

        for (int r = 0; r < rows; ++r){
            for (int c = 0; c < cols; ++c){
                if (rowZero[r] || colZero[c]){
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
