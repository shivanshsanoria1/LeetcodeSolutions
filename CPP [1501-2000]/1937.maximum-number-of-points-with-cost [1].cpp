class Solution {
private:
    typedef long long int lli;

public:
    // T.C.=O(m*n), S.C.=O(4*n)
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size(), n=points[0].size();
        vector<lli> dp_prev(n, 0);
        vector<lli> dp_curr(n, 0);

        for(int j=0; j<n; j++)
            dp_prev[j] = points[0][j]; 

        for(int i=1; i<m; i++)
        {
            vector<lli> dp_left(n, 0);
            vector<lli> dp_right(n, 0);

            dp_left[0] = dp_prev[0];
            for(int j=1; j<n; j++)
                dp_left[j] = max(dp_left[j-1] - 1, dp_prev[j]);
            
            dp_right[n-1] = dp_prev[n-1];
            for(int j=n-2; j>=0; j--)
                dp_right[j] = max(dp_right[j+1] - 1, dp_prev[j]);

            for(int j=0; j<n; j++)
                dp_curr[j] = points[i][j] + max(dp_left[j], dp_right[j]);

            dp_prev = dp_curr;
        }
        
        return *max_element(dp_prev.begin(), dp_prev.end());
    }
};