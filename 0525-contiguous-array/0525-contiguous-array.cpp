class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        int currsum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currsum+=1;
            }else{
                currsum+=-1;
            }
            if(mp.find(currsum)!=mp.end()){
                ans=max(ans,i-mp[currsum]);

            }else{
                mp[currsum]=i;
            }
        }
        return ans;
    }
};