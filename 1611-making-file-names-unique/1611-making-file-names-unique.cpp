class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int>mp;
        vector<string>ans;
        for(string name:names){ //new entry
            if(mp.find(name)==mp.end()){
                ans.push_back(name);
                mp[name]=1;

            }
            else{//already exists like gta(1)
            int k=mp[name];
            string new_name=name + "(" + to_string(k) + ")";
            while(mp.find(new_name)!=mp.end()){
                k++;
                new_name=name+ "("+ to_string(k)+")";
            }
            ans.push_back(new_name);
            mp[name]=k+1;
            mp[new_name]=1;
            }
        }
        return ans;
    }
};