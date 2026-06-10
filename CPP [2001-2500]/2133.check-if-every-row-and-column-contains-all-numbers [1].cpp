class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) { //1<=matrix[i][j]<=n
        int n=matrix.size();
        unordered_set<int> s;
        for(int i=0; i<n; i++) //check rows
        {
            for(int j=0; j<n; j++)
                s.insert(matrix[i][j]);
            if(s.size()!=n)
                return false;
            s.clear();
        }
        for(int j=0; j<n; j++) //check cols
        {
            for(int i=0; i<n; i++)
                s.insert(matrix[i][j]);
            if(s.size()!=n)
                return false;
            s.clear();
        }
        return true;
    }
};