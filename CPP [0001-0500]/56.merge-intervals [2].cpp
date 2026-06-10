class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(vector<int>& interval: intervals)
        {
            // no overlap between prev and curr intervals
            if(ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval);
            // merge the prev and curr intervals
            else
                ans.back()[1] = max(ans.back()[1], interval[1]);
        }

        return ans;
    }
};