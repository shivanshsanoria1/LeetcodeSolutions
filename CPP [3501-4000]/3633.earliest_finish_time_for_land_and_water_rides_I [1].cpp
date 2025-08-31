class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minTime = INT_MAX;

        // first land-ride then water-ride
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                int actualWaterStartTime = max(waterStartTime[j], landStartTime[i] + landDuration[i]);
                minTime = min(minTime, actualWaterStartTime + waterDuration[j]);
            }
        
        // first water-ride then land-ride
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int actualLandStartTime = max(landStartTime[j], waterStartTime[i] + waterDuration[i]);
                minTime = min(minTime, actualLandStartTime + landDuration[j]);
            }

        return minTime;
    }
};