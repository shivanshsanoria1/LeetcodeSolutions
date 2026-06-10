class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        for(int i=1, val=1; i<n; i+=2, val++){
            ans[i-1] = -val;
            ans[i] = val;
        }

        return ans;
    }
};