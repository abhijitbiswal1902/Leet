class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        map<int,int>m;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int x=__gcd(nums[i],k);
            int multiple=k/x;
            for(auto it:m){
                if(it.first % multiple ==0){
                ans+=it.second;}
                
            }
            m[x]++;

        }
        return ans;
    }
};