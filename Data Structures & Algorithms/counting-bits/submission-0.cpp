class Solution {
public:
    vector<int> countBits(int n) {
        // 32 bit integers
        // we can go through the 32 bits and check if ith bit is 1 
        // by doing AND on the number and 2^i
        // not optimal soultion time O(nlogn)
        vector<int> res(n+1);
        for (int num = 1; num <= n; ++num){
            for (int i = 0; i < 32; ++i){
                if (num & (1 << i)){
                    res[num]++;
                }
            }
        }

        return res;
    }
};
