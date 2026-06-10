class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) { //1<=matrix[i][j]<=n
        int n=matrix.size();
        unordered_set<int> sr, sc;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) //check rows
                sr.insert(matrix[i][j]);
            for(int j=0; j<n; j++) //check cols
                sc.insert(matrix[j][i]);
            if(sr.size()!=n || sc.size()!=n)
                return false;
            sr.clear();
            sc.clear();
        }
        return true;
    }
};