class Solution {
    int ROWS,COLS;
    // set<pair<int,int>> path;
public:
    bool exist(vector<vector<char>>& board, string word) {
        // this is optimal backtracking. same runtime and space.
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; ++r){
            for (int c = 0; c < COLS; ++c){
                if (dfs(board,word,r,c,0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        if (i == word.length()){
            return true; // word was found!
        }

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != word[i] || board[r][c] == '#'){
            return false;
        }

        board[r][c] = '#';
        bool res = dfs(board, word, r + 1, c, i + 1) ||
                    dfs(board, word, r - 1, c, i + 1) || 
                    dfs(board, word, r, c + 1, i + 1) || 
                    dfs(board, word, r, c - 1, i + 1);
        board[r][c] = word[i]; //safe because we already check it was word[i].
        return res;
    }
};
