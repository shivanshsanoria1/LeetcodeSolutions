class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++)
        {
            int prevStart = ans.back()[0], prevEnd = ans.back()[1];
            int currStart = intervals[i][0], currEnd = intervals[i][1];

            // no overlap between [prevStart, prevEnd] and [currStart, currEnd]
            if(prevEnd < currStart)
                ans.push_back(intervals[i]);
            // merge intervals [prevStart, prevEnd] and [currStart, currEnd]
            else if(prevEnd >= currStart && prevEnd <= currEnd)
                ans.back()[1] = currEnd;
        }

        return ans;
    }
};