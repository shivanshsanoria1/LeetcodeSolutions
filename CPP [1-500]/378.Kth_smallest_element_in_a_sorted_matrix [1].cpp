class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        vector<int> vec(n*n);
        int c=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                vec[c]=matrix[i][j];
                c++;
            }
        }
        sort(vec.begin(),vec.end());
        return vec[k-1];
    }
};