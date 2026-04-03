class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // the rows get converted to columns in that order
        // that is the same as transposing the matrix.
        // BUT we need the reverse order of that (i.e. first row -> last column).
        // so first we reverse the matrix and then transpose: swap elements across diagonal.
        reverse(matrix.begin(), matrix.end()); //  first row is last row now

        for (int i = 0; i < matrix.size(); ++i){
            for (int j = i + 1; j < matrix[i].size(); ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
