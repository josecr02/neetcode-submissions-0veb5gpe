class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // backtracking problem.
        // same efficiency as DP.
        // open - number of '(' used.
        // close - number of ')' used.
        // O(4^n / root(n))
        vector<string> res;
        string parStack;
        backtrack(0, 0, n, res, parStack);
        return res;
    }

    void backtrack(int openN, int closedN, int n, vector<string>& res, string& parStack){
        if (openN == closedN && openN == n){
            // complete!
            res.push_back(parStack);
            return;
        }
        if (openN < n){
            parStack += '(';
            backtrack(openN + 1, closedN, n, res, parStack);
            parStack.pop_back(); // strings also have this
        }
        if (closedN < openN){
            parStack += ')';
            backtrack(openN, closedN + 1, n, res, parStack);
            parStack.pop_back();
        }
    }
};
