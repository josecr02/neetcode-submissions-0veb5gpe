class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res = {""}; // start with empty string
        vector<string> digitToChar = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz"
        };

        for (char digit : digits) {
            vector<string> tmp;
            for (string &curStr : res) {
                for (char c : digitToChar[digit - '0']) { // convert the digit char to number
                    tmp.push_back(curStr + c); // add each character to every current possible string
                }
            }
            res = tmp; // update the result with the new possible characters for each of the possible strings
        }
        return res;
    }
};