class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> ans(n, -1);

        for(int i=0; i<n; i++)
        {
            int s1 = intervals[i][0], e1 = intervals[i][1];
            int minS2 = INT_MAX;
            int idx = -1;

            for(int j=0; j<n; j++)
            {
                int s2 = intervals[j][0], e2 = intervals[j][1];

                if(s2 >= e1 && s2 < minS2)
                {
                    minS2 = s2;
                    idx = j;
                }
            }

            ans[i] = idx;
        }

        return ans;
    }
};