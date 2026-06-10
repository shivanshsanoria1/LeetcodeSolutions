class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    // n: size of difficulty[] and profit[], m: size of worker[]
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int totalProfit = 0;

        for(int maxDiff: worker)
        {
            int maxProfit = 0;

            for(int i=0; i<difficulty.size(); i++)
                if(difficulty[i] <= maxDiff)
                    maxProfit = max(maxProfit, profit[i]);

            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};