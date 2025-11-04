class Solution {
public:
    string generate(string &s){
        int count[26]={0};
        for(char ch:s){
            count[ch-'a']++;
        }
        string new_s;
        for(int i=0;i<26;i++){
            if(count[i]>0){
                new_s+=string(count[i],i+'a');

            }
        }
        return new_s;

    } 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string &s :strs){
            string new_s=generate(s);
            mp[new_s].push_back(s);

        }
        vector<vector<string>>res;
        for(auto & it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};