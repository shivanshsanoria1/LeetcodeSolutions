class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) //same matrix (0 rotation)
            return true;
        int n=mat.size(), deg=3;
        while(deg--) //deg=3 (90 CW rotation), deg=2 (180 CW rotation), deg=1 (270 CW rotation), deg=0 (360 CW rotation)
        {
            for(int i=0; i<n; i++) //transpose of matrix
                for(int j=i; j<n; j++)
                    if(i!=j)
                        swap(mat[i][j],mat[j][i]);
            for(int i=0; i<n; i++) //reflection of matrix
                reverse(mat[i].begin(),mat[i].end());
            if(mat==target)
                return true;
        }
        return false;
    }
};