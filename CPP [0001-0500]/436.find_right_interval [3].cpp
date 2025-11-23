class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // start -> index
        map<int, int> mp;

        for(int i=0; i<n; i++)
        {
            int s = intervals[i][0], e = intervals[i][1];
            mp[s] = i;
        }

        vector<int> ans(n, -1);

        for(int i=0; i<n; i++)
        {
            int s = intervals[i][0], e = intervals[i][1];
            
            // iterator to the first key with 
            // start value >= end of the ith interval
            auto itr = mp.lower_bound(e);

            if(itr != mp.end())
                ans[i] = itr->second;   
        }

        return ans;
    }
};