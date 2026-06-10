class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=accounts.size(), n=accounts[0].size();
        int max_row_sum=0, row_sum;
        for(int i=0; i<m; i++)
        {
            row_sum=0;
            for(int j=0; j<n; j++)
                row_sum += accounts[i][j];
            max_row_sum= max(max_row_sum,row_sum);
        }
        return max_row_sum;
    }
};  