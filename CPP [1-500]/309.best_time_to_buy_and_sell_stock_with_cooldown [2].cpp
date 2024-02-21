class Solution {
public:
    int maxProfit(vector<int>& prices) { // State Space Diagram, T.C.=O(n), S.C.=O(n)
        int n=prices.size();
        vector<int> s0(n, 0);
        vector<int> s1(n, 0); 
        vector<int> s2(n, 0);
        s1[0] = -prices[0];
        for(int i=1; i<n; i++)
        {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
            s2[i] = s1[i-1] + prices[i];
        }
        return max(s0[n-1], s2[n-1]);
    }
};
/*
# draw the state space diagram -
# each state can be of type X or Y
# type X: has no stock currently, type Y: has stock currently
# S0: type X, S1: type Y, S2: type X
# from S0 hold stock to remain at S0 or buy stock to reach S1
# from S1 hold stock to remain at S1 or sell stock to reach S2
# from S2 hold stock to reach S0
*/