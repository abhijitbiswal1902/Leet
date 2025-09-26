class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int zeroes = 0;
        int maxlen = 0;
        int currlen = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroes++;
                // right++;
            }
            while (zeroes > k) {
                if (nums[left] == 0) 
                    zeroes--;
                    left++;
                
            }
            if (zeroes <= k) {
                currlen = right - left + 1;
                maxlen = max(maxlen, currlen);
                
            }
            right++;
            
        }
        return maxlen;
    }
};