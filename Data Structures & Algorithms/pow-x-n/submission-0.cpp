class Solution {
public:
    double myPow(double x, int n) {
        // repeatedly square the base and halve the exponent
        if (x == 0) return 0;
        if (n == 0) return 1;

        double res = 1;
        long power = abs((long)n); // long because n can be MIN_INT and can overflow

        while (power){
            if (power & 1){
                // power is odd
                res *= x;
            }
            x *= x;
            power >>= 1; // divide power by 2
        }

        return n >= 0 ? res : 1 / res; // we can have negative n given
        // O(logn)
    }
};
