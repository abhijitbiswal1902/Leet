class Solution {
public:
    int calculate(string s) {
        int num=0;
        int res=0;
        stack<int>st;
        int sign=1;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num=num*10 + (s[i]-'0');
            }
            if(s[i]=='+'){
                res+=(num*sign);
                num=0;
                sign=1;

            }
            if(s[i]=='-'){
                res+=(num*sign);
                num=0;
                sign= -1;

            }
            if(s[i]=='('){
                st.push(res);
                st.push(sign);
                num=0;
                res=0;
                sign=1;

            }
            if(s[i]==')'){
                res+=(num*sign);
                num=0;
                int last_sign=st.top();st.pop();
                int last_res=st.top();st.pop();
                res*=last_sign;
                res+=last_res;

            }
        }
        res+=(num*sign);
        return res;
    }
};