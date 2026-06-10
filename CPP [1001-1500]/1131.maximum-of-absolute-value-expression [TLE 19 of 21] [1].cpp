class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int ans = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                ans = max(ans, abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i-j));
        return ans;
    }
};