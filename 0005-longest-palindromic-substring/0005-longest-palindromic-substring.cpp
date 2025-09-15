class Solution {
public:
    string longestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        int maxLen = 0;
        int endIndex = 0; 
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                   
                    int before = n - j; 
                    if (dp[i][j] > maxLen && before + dp[i][j] - 1 == i-1) {
                        maxLen = dp[i][j];
                        endIndex = i-1;
                    }
                }
            }
        }
        
        return s.substr(endIndex - maxLen + 1, maxLen);
    }
};
