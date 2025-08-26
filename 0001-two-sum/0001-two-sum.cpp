class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>values;
        for(int i=0;i<nums.size();i++){
            if(values.find(target-nums[i])==values.end()){
                values[nums[i]]=i;
            }
            else{
                return {values[target-nums[i]],i};
            }
        }
        return{-1,1};
    }
};