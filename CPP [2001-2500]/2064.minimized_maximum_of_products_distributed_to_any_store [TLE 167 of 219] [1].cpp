class Solution {
public:
    // T.C.=O(q*m), S.C.=O(1)
    // m: max-val in quantities[]
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxVal = *max_element(quantities.begin(), quantities.end());

        // range of values of divisor is [1, maxVal]
        for(int div = 1; div <= maxVal; div++)
        {
            long long int pieces = 0;
            for(int quantity: quantities)
            {
                // round-up division
                pieces += quantity % div == 0 ? quantity/div : quantity/div + 1;
                if(pieces > n)
                    break;
            }
            
            if(pieces <= n)
                return div;
        }

        return -1;
    }
};
// prerequisite: [1283. find-the-smallest-divisor-given-a-threshold]
// similar: [1870. minimum-speed-to-arrive-on-time]