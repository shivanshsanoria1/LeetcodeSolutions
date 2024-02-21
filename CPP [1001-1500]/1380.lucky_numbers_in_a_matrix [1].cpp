class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) { //T.C.=O(m*n) , S.C.=O(m+n)
        int m=matrix.size(), n=matrix[0].size();
        vector<int> rows, cols, ans;
        for(int i=0; i<m; i++) //find min element in each row
        {
            int min_row=INT_MAX;
            for(int j=0; j<n; j++)
                min_row=min(min_row,matrix[i][j]);
            rows.push_back(min_row);
        }
        for(int j=0; j<n; j++) //find max element in each col
        {
            int max_col=INT_MIN;
            for(int i=0; i<m; i++)
                max_col=max(max_col,matrix[i][j]);
            cols.push_back(max_col);
        }
        for(int i=0; i<m; i++) //find the common elements in min rows and max col vectors
            for(int j=0; j<n; j++)
                if(rows[i]==cols[j])
                    ans.push_back(rows[i]);
        return ans;
    }
};