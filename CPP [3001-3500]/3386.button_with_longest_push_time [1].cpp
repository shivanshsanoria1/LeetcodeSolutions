class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size();
        int maxTime = events[0][1];
        int ans = events[0][0];

        for(int i=1; i<n; i++)
        {
            int prevTime = events[i-1][1];
            int currIdx = events[i][0], currTime = events[i][1];

            if(currTime - prevTime > maxTime)
            {
                maxTime = currTime - prevTime;
                ans = currIdx;
            }
            else if(currTime - prevTime == maxTime)
                ans = min(ans, currIdx);
        }

        return ans;
    }
};