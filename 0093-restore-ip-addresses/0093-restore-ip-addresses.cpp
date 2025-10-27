class Solution {
public:
    vector<string>res;
    bool isValid(const string&s){
        if(s.size()>1 && s[0]=='0') return false;
        int val=stoi(s);
        return val<=255;
    }
    void backtrack(string&s,int idx,int parts,string curr){
        if(parts==4 && idx==s.size()){
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        if(parts>=4) return;
        for(int len=1;len<=3 && idx+len<=s.size();len++){
            string part=s.substr(idx,len);
            if(isValid(part))
            backtrack(s,idx+len,parts+1,curr+part+".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12) return {};
        backtrack(s,0,0,"");
        return res;
    }
};