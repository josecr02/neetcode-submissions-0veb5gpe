class Solution {
public:
// backtracking solution
    // O(n4^n) for space and time, and also O(n) extra space.
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(0, "", digits);
        return res;
    }

    void backtrack(int i, string curStr, string &digits){
        if (curStr.size() == digits.size()){
            res.push_back(curStr);
            return;
        }
        // chars to try
        string chars = digitToChar[digits[i] - '0']; // digits[i] - '0' converts it to numerical
        for (char c : chars){
            backtrack(i+1, curStr + c, digits);
        }
    }
};
