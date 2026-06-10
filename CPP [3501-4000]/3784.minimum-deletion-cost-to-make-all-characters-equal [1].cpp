class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    long long minCost(string s, vector<int>& cost) {
        vector<long long int> charCostSum(26, 0);
        for(int i=0; i<s.length(); i++)
            charCostSum[s[i] - 'a'] += cost[i];

        long long int totalSum = accumulate(charCostSum.begin(), charCostSum.end(), 0LL);
        long long int maxSum = *max_element(charCostSum.begin(), charCostSum.end());

        return totalSum - maxSum;
    }
};