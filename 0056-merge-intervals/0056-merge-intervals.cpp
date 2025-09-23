class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int ind=0;
        for(int i=0;i<n;i++){
            if(intervals[ind][1]>=intervals[i][0]){
                intervals[ind][1]=max(intervals[ind][1],intervals[i][1]);
            }
            else {
                ind++;
                intervals[ind]=intervals[i];
            }
        }
        return vector<vector<int>>(intervals.begin(),intervals.begin()+ind+1);
    }
};