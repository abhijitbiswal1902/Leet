class Solution {
public:
    int expand(string &s,int left,int right){
        int n=s.size();
        while(left >=0 && right <=n && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
        //(right-1)+(left+1)+1
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1) return s;
        int start=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            int len1=expand(s,i,i); //odd
            int len2=expand(s,i,i+1); //even
            int len=max(len1,len2);
            if(len>maxlen){
                maxlen=len;
                start=i-(len-1)/2;
            }
            
        }
        return s.substr(start,maxlen);
    }
};