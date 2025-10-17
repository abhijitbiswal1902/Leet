class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        long long ans=0;
        for(int num:nums){
            int g=gcd(num,k);
            int need=k/g;

            for(auto it:freq){
                if((1LL * g * it.first)%k==0)
                    ans+=it.second;
                
            }
            freq[g]++;
        }
        return ans;
    }
};