class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int r1=0;r1<m;r1++){
            for(int r2=0;r2<m;r2++){
                if(r1==r2) dp[n-1][r1][r2]=grid[n-1][r1];
                else{
                    dp[n-1][r1][r2]=grid[n-1][r1]+grid[n-1][r2];
                }

            }
        }
        for(int i=n-2;i>=0;i--){
            for(int r1=0;r1<m;r1++){
                for(int r2=0;r2<m;r2++){
                    int maxi=-1e8;
                    for(int a=-1;a<=1;a++){
                        for(int b=-1;b<=1;b++){
                            int value=0;
                            if(r1==r2) value=grid[i][r1];
                        
                        else value=grid[i][r1]+grid[i][r2];
                        if(r1+a >=0 && r1+a <m && r2+b >=0 && r2+b<m)
                        value+=dp[i+1][r1+a][r2+b];
                        else value+=-1e8;
                        maxi=max(maxi,value);
                    }
                }
                dp[i][r1][r2]=maxi;
            }}
        }
        return dp[0][0][m-1];
        
    }
};