class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int totalTime = 0;
        // sum of all the times in window
        int windowTime = neededTime[0];
        // max time from the window
        int maxTimeOfWindow = neededTime[0];
        for(int i=1; i<n; i++)
        {
            if(colors[i-1] == colors[i])
            {
                // add the curr time to the window time
                windowTime += neededTime[i];
                // find the max time from the window
                maxTimeOfWindow = max(maxTimeOfWindow, neededTime[i]);
            }
            else
            {
                // add the sum of window (except the max time) to the total time
                totalTime += windowTime - maxTimeOfWindow;
                // reset the window time with curr time
                windowTime = neededTime[i];
                // reset the max time with curr time
                maxTimeOfWindow = neededTime[i];
            }
        }
        // check required for the last window
        totalTime += windowTime - maxTimeOfWindow;
        return totalTime;
    }
    // a window consists of only same colored balloons
};