class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(const vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        int left = 0, sum = 0, count = 0;
        for (int right = 0; right < (int)nums.size(); ++right) {
            sum += nums[right];
            while (sum > k) {
                sum -= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }
};

// unordered_map<int,int>mappp;
// mappp[0]=1;
// int prefix=0;
// int count=0;
// for(int i=0;i<nums.size();i++){
//     prefix+=nums[i];
//     int remove=prefix-goal;
//     count+=mappp[remove];
//     mappp[prefix]+=1;
// }
// return count;

// THIS APPROACH WORKS BUT USES EXTRA SPACE FOR HASHING
// THIS CAN FURTHER BE REDUCED TO SC=O(1);
// THIS QS IS SIMILAR TO SUBARRAY SUM EQUALS TO K;