class Solution {
public:
    void backtrack(vector<string>& result, string curr, int open, int close, int n) {
        // base case: if string is complete
        if (curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // if we can still add '('
        if (open < n)
            backtrack(result, curr + "(", open + 1, close, n);

        // if we can add ')'
        if (close < open)
            backtrack(result, curr + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
