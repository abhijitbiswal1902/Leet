class Solution {
public:
    void ways(int ind, int target, vector<vector<int>>& ans, vector<int>& temp,
              vector<int>& arr) {
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if (arr[ind] <= target) {
            temp.push_back(arr[ind]);
            ways(ind, target - arr[ind], ans, temp, arr); //lenge
            temp.pop_back(); //nahi lene k liye nikal lenge
        }

        ways(ind + 1, target, ans, temp, arr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        ways(0, target, ans, temp, candidates);
        return ans;
    }
};
