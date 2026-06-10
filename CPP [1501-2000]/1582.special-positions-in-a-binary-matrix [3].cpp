class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) { // T.C.=O(m*n), S.C.=O(m+n)
        int m=mat.size(), n=mat[0].size();
        // assume all rows and cols are invalid initially
        vector<bool> isRowValid(m, false), isColValid(n, false);

        for(int i=0; i<m; i++) // find if the row is valid or not
        {
            int sum = 0;
            for(int j=0; j<n; j++)
            {
                sum += mat[i][j];
                if(sum > 1)
                    break;
            }
            if(sum == 1)
                isRowValid[i] = true;
        }
        
        for(int j=0; j<n; j++) // find if the col is valid or not
        {
            int sum = 0;
            for(int i=0; i<m; i++)
            {
                sum += mat[i][j];
                if(sum > 1)
                    break;
            }
            if(sum == 1)
                isColValid[j] = true;
        }

        int count = 0;
        for(int i=0; i<m; i++)
            if(isRowValid[i])
                for(int j=0; j<n; j++)
                    if(mat[i][j] == 1 && isColValid[j])
                    {
                        count++;
                        break;
                    }

        return count;
    }
};