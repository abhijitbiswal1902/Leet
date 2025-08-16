class Solution {
public:
    void subsets(int ind,vector<int>&nums,vector<int>&tempo,vector<vector<int>>&ans){
        ans.push_back(tempo);
        for(int i=ind;i<nums.size();i++){
            if(i !=ind && nums[i]==nums[i-1]) continue;
            tempo.push_back(nums[i]);
            subsets(i+1,nums,tempo,ans);
            tempo.pop_back();
            // subsets(ind+1,nums,ans,temp);
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tempo;
        sort(nums.begin(),nums.end());
        subsets(0,nums,tempo,ans);
        return ans;
    }
};