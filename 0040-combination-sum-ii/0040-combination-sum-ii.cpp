class Solution {
public:
    void ways(int ind,int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=ind;i<candidates.size();i++){
            if(candidates[i]>target)break;
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            ways(i+1,target-candidates[i],candidates,ans,temp);
            temp.pop_back();
        }

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        ways(0,target,candidates,ans,temp);
        return ans;

    }
};