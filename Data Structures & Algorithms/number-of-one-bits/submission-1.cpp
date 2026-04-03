class Solution {
public:
    int hammingWeight(uint32_t n) {

        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((1 << i) & n) {
                res++;
            }
        }
        return res;

        // 16 8 0
        // 8 4 0
        // 4 2 0
        // 2 1 0
        // 1 0 1


        // 3 1 1
        // 1 0 1
    }
};
