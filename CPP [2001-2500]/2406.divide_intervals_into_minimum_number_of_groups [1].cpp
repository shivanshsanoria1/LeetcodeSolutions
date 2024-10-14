class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    // Line-Sweep algo.
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(vector<int>& interval: intervals)
        {
            int start = interval[0];
            int end = interval[1];

            // interval is active in time-range [start, end]
            // so it becomes inactive at (end + 1)
            mp[start]++;
            mp[end + 1]--;
        }

        int activeIntervalsCount = 0;
        int ans = 0;
        for(auto [time, netChange]: mp)
        {
            activeIntervalsCount += netChange;
            ans = max(ans, activeIntervalsCount);
        }

        return ans;
    }
};

// just find the max num of intersecting intervals at any moment of time