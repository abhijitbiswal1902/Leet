class Solution {
public:
    int calculate(string s) {
        int number=0;
        int result=0;
        int sign=1;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                number=number*10 + (s[i]-'0');

            }
            if(s[i]=='+'){
                result+=(number*sign);
                number=0;
                sign=1;

            }
            if(s[i]=='-'){
                result+=(number*sign);
                number=0;
                sign=-1;

            }
            if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }
            if(s[i]==')'){
                result+=(number*sign);
                number=0;
                int last_sign=st.top();st.pop();
                int last_Res=st.top();st.pop();
                result *=last_sign;
                result += last_Res;
            }
        }
        result+=(number*sign);
        return result;
    }
};