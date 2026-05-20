class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n-1] = 1; // end

        for (int i = m-1; i >=0; --i){
            for (int j = n-1; j >=0; --j){
                dp[i][j] += dp[i+1][j] + dp[i][j+1];
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
            }
        }

        return dp[0][0];
    }
};