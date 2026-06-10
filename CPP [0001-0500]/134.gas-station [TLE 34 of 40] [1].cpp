class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if(totalGas < totalCost)
            return -1;
            
        int n=gas.size();
        for(int i=0; i<n; i++)
        {
            int n2 = n;
            int currGas = 0;
            for(int j=i; n2 > 0; j = (j+1) % n, n2--)
            {
                currGas += (gas[j] - cost[j]);
                if(currGas < 0)
                    break;
            }
            if(n2 == 0)
                return i;
        }
        return -1;
    }
};