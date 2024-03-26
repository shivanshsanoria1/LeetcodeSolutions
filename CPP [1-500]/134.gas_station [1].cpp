class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if(totalGas < totalCost)
            return -1;

        int n=gas.size();
        int currGas = 0;
        int idx = 0;
        for(int i=0; i<n; i++)
        {
            currGas += (gas[i] - cost[i]);
            if(currGas < 0)
            {
                // reset 'currGas'
                currGas = 0;
                // index 'i' cannot be the ans, 
                // 'i+1' can be the next possible ans
                idx = i+1;
            }
        }
        return idx;
    }
};