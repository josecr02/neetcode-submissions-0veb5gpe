class Solution {
public:
    int climbStairs(int n) {
        
        int one = 1, two = 1;

        for (int i = 0 ; i < n - 1; ++i){
            int temp = one;
            one = one + two; // the new current step can be reached with the same ways as previous current and
            // the previous to the previous current
            two = temp; // now the next previous (last current) has the same ways as the initial current ways
        }

        return one;
    }
};
