class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0;
        int right =0;
        int n=cardPoints.size();
        int maxi=0;
        for(int i=0;i<=k-1;i++){
            left=left+cardPoints[i];
            maxi=left;
        }
        int rightindex=n-1;
        for(int i=k-1;i>=0;i--){
            left=left-cardPoints[i];
            right=right+cardPoints[rightindex];
            rightindex=rightindex-1;
            maxi=max(maxi,left+right);

        }
        return maxi;
    }
};