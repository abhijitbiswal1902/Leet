class Solution {
public:
    bool checkValidString(string s) {
        int open=0;
        int close=0;
        int star=0;
        for(char c :s){
            if (c=='('){
                open++;
            }
            else if(c==')'){
                close++;
            }
            else if(c=='*'){
                star++;
            }
            // if(star<(close-open)){
            //     return false;
            // }
            if(close>star+open){
                return false;
            }
        }
        open=0;
        close=0;
        star=0;
        for(int i=s.size()-1;i>=0;i--){
            char c=s[i];
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                close++;
            }
            else if(s[i]=='*'){
                star++;
            }
            
            if(open > star+close){
                return false;
            }
        
        }
        return true;
    }
};