class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mpp;
        int currsum=0;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currsum+=1;
            }
            else {
                currsum+=-1;
            }
            if(mpp.find(currsum)!=mpp.end()){
                ans=max(ans,i-mpp[currsum]);
            }
            else{
                mpp[currsum]=i;
            }

        }
        return ans;
    }
};