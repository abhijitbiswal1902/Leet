class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        for (int i = n - 1; i > 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int mini = 1e9;
                for (int k = i; k < j; k++) {
                    int steps = values[i - 1] * values[k] * values[j] +
                                dp[i][k] + dp[k + 1][j];
                    if (steps < mini) {
                        mini = steps;
                    }
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n - 1];
    }
};