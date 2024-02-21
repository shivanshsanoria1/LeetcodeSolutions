class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int k1 = 0, k2 = 0;
        int num = 1;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                k1 += grid[i][j] - num;
                k2 += grid[i][j] * grid[i][j] - num*num;
                num++;
            }
        vector<int> ans(2, 0);
        ans[0] = (k1 + k2/k1) / 2; // duplicate num
        ans[1] = (k2/k1 - k1) / 2; // missing num
        return ans;
    }
};
/*
# Math soln.
# ans[0]: duplicate num, ans[1]: missing num
# let d: duplicate num
# let m: missing num
# let sum1: sum of all nums of grid
# let sum2: sum of square of all nums of grid
# let S1` = 1 + 2 + 3 + ... + n*n
# let S2` = 1^2 + 2^2 + 3^2 + ... + (n*n)^2
# sum1 = S1` + d - m
# sum2 = S2` + d^2 - m^2 
# k1 = sum1 - S1` = (d - m)
# k2 = sum2 - S2` = d^2 - m^2 = (d + m)*(d - m) = (d + m) * k1
# d - m = k1
# d + m = k2/k1
# d = (k1 + k2/k1) / 2
# m = (k2/k1 - k1) / 2
*/