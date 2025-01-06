class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n, 0);

        int prefixSum = 0, ops_left = 0;
        for(int i=0; i<n; i++)
        {
            ans[i] += ops_left;
            prefixSum += boxes[i] - '0';
            ops_left += prefixSum;
        }

        int postfixSum = 0, ops_right = 0;
        for(int i=n-1; i>=0; i--)
        {
            ans[i] += ops_right;
            postfixSum += boxes[i] - '0';
            ops_right += postfixSum;
        }

        return ans;
    }
};