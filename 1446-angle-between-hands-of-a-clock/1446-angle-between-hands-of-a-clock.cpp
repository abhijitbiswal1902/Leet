class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr=(hour%12+minutes/60.0)*30;
        double mins=6*minutes;
        double ans=fabs(hr-mins);
        if (ans>=180.0){
            ans=360.0-ans;
        }
        return ans;
    }
};