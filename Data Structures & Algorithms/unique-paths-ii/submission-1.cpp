class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // same but space is optimized
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n+1, 0);
        dp[n-1] = 1; // end

        for (int i = m-1; i >=0; --i){
            for (int j = n-1; j >=0; --j){
                if (obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j+1];
                }
                
                
            }
        }

        return dp[0];
    }
};