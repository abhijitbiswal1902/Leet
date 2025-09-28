class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
    
      unordered_map<string,int>mapp;
      vector<string>ans;
      
      for(string name: names){
        if(mapp.find(name)==mapp.end()){
            ans.push_back(name);
            mapp[name]=1;
        }
        else{
            int k=mapp[name];
            string newName =name+ "(" + to_string(k) + ")";
            while(mapp.find(newName)!=mapp.end()){
                k++;
                newName=name+"("+ to_string(k) + ")";
            }
            ans.push_back(newName);
            mapp[name]=k+1;
            mapp[newName]=1;

        }
      }
      return ans;

    }
};