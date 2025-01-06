class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ans[i] += abs(i-j) * (boxes[j] - '0');

        return ans;
    }
};