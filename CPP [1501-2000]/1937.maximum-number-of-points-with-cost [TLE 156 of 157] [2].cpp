class Solution {
private:
    typedef long long int lli;

public:
    // T.C.=O(m*n^2), S.C.=O(2*n)
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size(), n=points[0].size();
        vector<lli> dp_prev(n, 0);
        vector<lli> dp_curr(n, 0);

        for(int j=0; j<n; j++)
            dp_prev[j] = points[0][j]; 

        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                lli prevRowMax = LLONG_MIN;
                for(int k=0; k<n; k++)
                    prevRowMax = max(prevRowMax, dp_prev[k] - abs(j - k));

                dp_curr[j] = points[i][j] + prevRowMax;
            }
            
            dp_prev = dp_curr;
        }
        
        return *max_element(dp_prev.begin(), dp_prev.end());
    }
};