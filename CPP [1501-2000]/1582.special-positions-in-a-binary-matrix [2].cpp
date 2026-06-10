class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) { // T.C.=O(m*n), S.C.=O(m+n)
        int m=mat.size(), n=mat[0].size();
        vector<int> rowSums, colSums; // stores row and col sums
        for(int i=0; i<m; i++) // find the row sums
        {
            int sum = 0;
            for(int j=0; j<n; j++)
                sum += mat[i][j];
            rowSums.push_back(sum);
        }
        for(int j=0; j<n; j++) // find the col sums
        {
            int sum = 0;
            for(int i=0; i<m; i++)
                sum += mat[i][j];
            colSums.push_back(sum);
        }

        int count = 0;
        for(int i=0; i<m; i++)
            if(rowSums[i] == 1)
                for(int j=0; j<n; j++)
                    if(mat[i][j] == 1 && colSums[j] == 1)
                    {
                        count++;
                        break;
                    }
        return count;
    }
};