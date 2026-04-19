class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        // time O(mn) and space O(m + n)
        //  When we multiply digit i of num1 by digit j of num2, the result contributes to position i + j in the final answer.
        vector<int> res(num1.length() + num2.length(), 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i1 = 0; i1 < num1.length(); i1++) {
            for (int i2 = 0; i2 < num2.length(); i2++) {
                int digit = (num1[i1] - '0') * (num2[i2] - '0'); // we work with least important digits first!
                res[i1 + i2] += digit;
                res[i1 + i2 + 1] += res[i1 + i2] / 10;
                res[i1 + i2] %= 10;
            }
        }

        stringstream result;
        int i = res.size() - 1;
        while (i >= 0 && res[i] == 0) { // remove padded zeroes on left
            i--;
        }
        while (i >= 0) {
            result << res[i]; // put the actual result in stringstream
            --i;
        }
        return result.str();
    }
};