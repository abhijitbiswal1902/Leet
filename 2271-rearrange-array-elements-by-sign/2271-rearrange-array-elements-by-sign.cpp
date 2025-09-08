class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int p=0;
        int ne=1;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[p]=nums[i];
                p+=2;

            }
            else {
                ans[ne]=nums[i];
                ne+=2;

            }

        }
        nums=ans;
        return nums;
    }
};