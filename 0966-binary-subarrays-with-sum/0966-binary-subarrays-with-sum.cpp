class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mappp;
        mappp[0]=1;
        int prefix=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int remove=prefix-goal;
            count+=mappp[remove];
            mappp[prefix]+=1;
        }
        return count;
    }
};