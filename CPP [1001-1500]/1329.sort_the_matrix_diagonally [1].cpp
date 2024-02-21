class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        for(int j=0; j<n; j++) //0th row
        {
            int r=0, c=j;
            vector<int> temp; //to store diagonal elements
            while(r<m && c<n) //check the diagonals starting from matrix[0][j]
            {
                temp.push_back(mat[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(),temp.end()); //sort the diagonal elements
            int index=0;
            r=0, c=j;
            while(r<m && c<n) //store ths sorted values in the diagonal
            {
                mat[r][c]=temp[index];
                index++;
                r++;
                c++;
            }
        }
        for(int i=0; i<m; i++) //0th col
        {
            int r=i, c=0;
            vector<int> temp; //to store diagonal elements
            while(r<m && c<n) //check the diagonals starting from matrix[0][j]
            {
                temp.push_back(mat[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(),temp.end()); //sort the diagonal elements
            int index=0;
            r=i, c=0;
            while(r<m && c<n) //store ths sorted values in the diagonal
            {
                mat[r][c]=temp[index];
                index++;
                r++;
                c++;
            }
        }
        return mat;
    }
};