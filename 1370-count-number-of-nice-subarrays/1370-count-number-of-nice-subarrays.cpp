class Solution {
public:
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
    int helper(vector<int>&nums,int k){
             if (k < 0)
            return 0;
        int left = 0, sum = 0, count = 0;
        for (int right = 0; right < (int)nums.size(); ++right) {
            sum += nums[right]%2;
            while (sum > k) {
                sum -= nums[left++]%2;
            }
            count += right - left + 1;
        }
        return count;
    }
};
