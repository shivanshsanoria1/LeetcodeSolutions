class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) { 
        vector<int> ans;
        for(int point: queries)
        {
            int minSize = INT_MAX; // min interval size
            for(auto& interval: intervals)
            {
                int start = interval[0], end = interval[1];
                if(start <= point && point <= end) // query point lies in interval
                    minSize = min(minSize, end - start + 1);
            }
            if(minSize == INT_MAX) // no interval found for query point
                minSize = -1;
            ans.push_back(minSize);
        }
        return ans;
    }
};
// T.C.=O(n*q), S.C.=O(1), n: length of intervals[], q: length of queries[]