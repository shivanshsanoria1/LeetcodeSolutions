class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> minOperations(string boxes) {
        int n = boxes.length();

        vector<int> left(n, 0);
        int prefixSum = boxes[0] - '0';
        for(int i=1; i<n; i++)
        {
            left[i] += prefixSum + left[i-1];
            prefixSum += (boxes[i] - '0');
        }
        
        vector<int> right(n, 0);
        int postfixSum = boxes[n-1] - '0';
        for(int i=n-2; i>=0; i--)
        {
            right[i] += postfixSum + right[i+1];
            postfixSum += (boxes[i] - '0');
        }

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++)
            ans[i] = left[i] + right[i];

        return ans;
    }
};