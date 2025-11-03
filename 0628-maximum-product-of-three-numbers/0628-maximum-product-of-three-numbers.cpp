class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        //-100,-99,1,2,3,4
        sort(nums.begin(),nums.end());
        int leftmost=nums[0]*nums[1]*nums[n-1];
        int rightmost=nums[n-1]*nums[n-2]*nums[n-3];
        return max(leftmost,rightmost);
        

    }
};