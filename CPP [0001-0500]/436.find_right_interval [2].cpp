class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    // Binary-search
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // { start, index }
        vector<pair<int, int>> vec(n);

        for(int i=0; i<n; i++)
        {
            int s = intervals[i][0], e = intervals[i][1];
            vec[i] = {s, i};
        }

        sort(vec.begin(), vec.end());

        vector<int> ans(n, -1);

        for(int i=0; i<n; i++)
        {
            int s1 = intervals[i][0], e1 = intervals[i][1];
            int left = 0, right = n-1;
            int idx = -1;

            while(left <= right)
            {
                int mid = left + (right - left)/2;
                auto [s2, j] = vec[mid];

                if(s2 >= e1)
                {
                    idx = j;
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }

            ans[i] = idx;   
        }

        return ans;
    }
};