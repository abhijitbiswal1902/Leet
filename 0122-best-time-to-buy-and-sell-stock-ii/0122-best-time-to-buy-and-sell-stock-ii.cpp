class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buylater=0,selllater=0;
        for(int i=n-1;i>=0;i--){
            int currbuy=max(-prices[i]+selllater,buylater);
            int currsell=max(prices[i]+buylater,selllater);
            buylater=currbuy;
            selllater=currsell;
        }
        return buylater;
    }
};