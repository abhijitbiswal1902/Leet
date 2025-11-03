class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left,right=0;
        int maxlen=0;
        int n=nums.size();
        int zeroes=0;
        while(right<n){
            if(nums[right]==0) zeroes++; //expand the window
            while(zeroes>k){ //shrink the window if zeroes exceed the k val
                if(nums[left]==0)
                zeroes--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;

        }
        return maxlen;
    }
};