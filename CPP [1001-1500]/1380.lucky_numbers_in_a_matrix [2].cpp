class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> ans;
        unordered_set<int> s;
        for(int i=0; i<m; i++)
        {
            int min_row=INT_MAX;
            for(int j=0; j<n; j++)
                min_row=min(min_row,matrix[i][j]);
            s.insert(min_row); //push min_row in set
        }
        for(int j=0; j<n; j++)
        {
            int max_col=INT_MIN;
            for(int i=0; i<m; i++)
                max_col=max(max_col,matrix[i][j]);
            if(s.find(max_col) != s.end()) //max_col already present in set
                ans.push_back(max_col); //push max_col in ans
        }
        return ans;
    }
};