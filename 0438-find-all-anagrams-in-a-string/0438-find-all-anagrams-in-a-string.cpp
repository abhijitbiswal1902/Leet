class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        vector<int> freqP(26, 0), freqS(26, 0);
        vector<int> ans;

        // Step 1: Build frequency for 'p' and first window of 's'
        for (int i = 0; i < m; i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        // Step 2: Slide the window across 's'
        for (int i = m; i < n; i++) {
            if (freqP == freqS)
                ans.push_back(i - m);  // store start index

            // Slide the window:
            freqS[s[i] - 'a']++;      // include next char
            freqS[s[i - m] - 'a']--;  // remove previous char
        }

        // Check last window
        if (freqP == freqS)
            ans.push_back(n - m);

        return ans;
    }
};
