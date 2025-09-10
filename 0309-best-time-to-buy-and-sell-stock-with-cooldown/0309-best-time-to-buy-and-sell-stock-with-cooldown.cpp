class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // int profit=0;
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        // dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else {
                dp[i][buy]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
                // dp[i][buy]=profit;


            }
        }
        return dp[0][1];
    }
};