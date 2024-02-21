class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) { // T.C.=O(m*n), S.C.=O(m*n)
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> mp(m+n-1);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                mp[i+j].push_back(mat[i][j]);

        vector<int> ans;
        for(int i=0; i<mp.size(); i++)
        {
            if(i % 2 == 1)
            {
                for(int j=0; j<mp[i].size(); j++)
                    ans.push_back(mp[i][j]);
            }
            else
            {
                for(int j=mp[i].size()-1; j>=0; j--)
                    ans.push_back(mp[i][j]);
            }
        }
        return ans;
    }
};
/*
# (i+j) varies from 0 to (m-1 + n-1), ie, (m+n-1) possible values
# idx: (i+j), mp[idx]: {mat[i][j]} 
*/