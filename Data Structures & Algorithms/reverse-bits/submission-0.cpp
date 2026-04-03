class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        // extract starting ast least significant
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i){
            uint32_t bit = (n >> i) & 1; // 0 or 1
            res += (bit << (31 - i));
        }

        return res;
    }
};
