class Solution {
public:
    int getNumLen(int num){
        if(num == 0)
            return 1;
        bool isNeg = num < 0;
        num = abs(num);
        int len = 0;
        while(num > 0)
        {
            num /= 10;
            len++;
        }
        return isNeg ? len + 1 : len;
    }

    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(n);
        for(int j=0; j<n; j++)
        {
            int maxLen = 0;
            for(int i=0; i<m; i++)
                maxLen = max(maxLen, getNumLen(grid[i][j]));
            ans[j] = maxLen;
        }
        return ans;
    }
};