class Solution {
public:
    int findKthNumber(int m, int n, int k) { // T.C.=O(m*n*log(m*n)), S.C.=O(m*n)
        vector<int> mul;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                mul.push_back((i+1)*(j+1));
        sort(mul.begin(), mul.end());
        return mul[k-1];
    }
};