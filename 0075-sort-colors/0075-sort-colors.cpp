class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0;
        int m=0;
        int e=nums.size()-1;
        while(m<=e){
            if(nums[m]==0){
                swap(nums[m],nums[s]);
                s++;
                m++;
            }
            else if(nums[m]==1){
                m++;
            }
            else {
                swap(nums[m],nums[e]);
                e--;
            }
        }
    }
};