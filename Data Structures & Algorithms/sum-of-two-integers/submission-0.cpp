class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0){
            int carry = (a & b) << 1; // AND with left shift
            a ^= b;
            b = carry;
        }
        return a;
    }
};
