class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n=timePoints.size();
        int minDiff = 24*60;
        for(int i=0; i<n; i++)
        {
            string hh1 = timePoints[i].substr(0, 2);
            string mm1 = timePoints[i].substr(3);
            int time1 = 60*stoi(hh1) + stoi(mm1);

            string hh2 = timePoints[(i+1) % n].substr(0, 2);
            string mm2 = timePoints[(i+1) % n].substr(3);
            int time2 = 60*stoi(hh2) + stoi(mm2);

            int diff = abs(time2 - time1);
            if(diff > 12*60)
                diff = 24*60 - diff;

            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }
};