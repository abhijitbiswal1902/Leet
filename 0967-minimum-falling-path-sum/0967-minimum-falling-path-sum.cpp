class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<int>prev(m,0),curr(n,0);
        for(int j=0;j<m;j++){
            prev[j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+prev[j];
                int left=matrix[i][j];
                if(j-1>=0) left+=prev[j-1];
                else 
                left+=1e9;
                int right=matrix[i][j];
                
                if(j+1<m)right+=prev[j+1];
                else right+=1e9;
                curr[j]=min(up,min(left,right));

            }
            prev=curr;
        }
        int maxi=1e9;
        for(int j=0;j<m;j++){
            maxi=min(maxi,prev[j]);
        }
    return maxi;
    }
};