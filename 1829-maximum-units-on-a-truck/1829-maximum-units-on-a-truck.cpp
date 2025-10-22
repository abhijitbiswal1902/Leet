class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),
        [](const vector<int>&a,const vector<int>&b){
            return a[1]>b[1];
        }
        );

        int ans=0;
        // int n=boxTypes[0].size();
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                ans+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else if(boxTypes[i][0]>truckSize){
                ans+=truckSize*boxTypes[i][1];
                truckSize=0;
            }
        }
        return ans;
    }
};