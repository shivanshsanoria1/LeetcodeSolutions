class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        vector<bool> rot(4,true); //checks if 0 deg, 90 deg, 180 deg, 270 deg rotation is possible or not
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] != target[i][j]) rot[0]=false; //check for 0 deg CW rotation
                if(mat[i][j] != target[j][n-1-i]) rot[1]=false; //check for 90 deg CW rotation
                if(mat[i][j] != target[n-1-i][n-1-j]) rot[2]=false; //check for 180 deg CW rotation
                if(mat[i][j] != target[n-1-j][i]) rot[3]=false; //check for 270 deg CW rotation
            }
        return rot[0] || rot[1] || rot[2] || rot[3];
    }
};