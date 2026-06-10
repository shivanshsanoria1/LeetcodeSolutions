class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        k = k % n;
        for(int i=0; i<m; i++)
        {
            vector<int> temp(n);

            // left-shift even indexed rows
            if(i % 2 == 0)
                for(int j=0; j<n; j++)  
                    temp[(j-k+n) % n] = mat[i][j];
            // right-shift odd indexed rows
            else
                for(int j=0; j<n; j++)  
                    temp[(j+k) % n] = mat[i][j];

            // check rows before and after shifting
            for(int j=0; j<n; j++)
                if(temp[j] != mat[i][j])
                    return false;
        }
        return true;
    }
};