class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) { // State Space Diagram, T.C.=O(n), S.C.=O(1)
        int n=prices.size();
        int s0 = 0;
        int s1 = -prices[0];
        for(int i=1; i<n; i++)
        {
            int tempS0 = s0, tempS1 = s1;
            s0 = max(tempS0, tempS1 + prices[i] - fee);
            s1 = max(tempS1, tempS0 - prices[i]);
        }
        return s0;
    }
};
/*
# draw the state space diagram -
# each state can be of type X or Y
# type X: has no stock currently, type Y: has stock currently
# S0: type X, S1: type Y
# from S0 hold stock to remain at S0 or buy stock to reach S1
# from S1 hold stock to remain at S1 or sell stock to reach S0
*/