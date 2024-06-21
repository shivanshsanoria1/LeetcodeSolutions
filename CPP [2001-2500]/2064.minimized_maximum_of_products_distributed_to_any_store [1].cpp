class Solution {
public:
    // T.C.=O(q*log(m)), S.C.=O(1)
    // m: max-val in quantities[]
    // Binary-search
    int minimizedMaximum(int n, vector<int>& quantities) {
        // range of values of divisor is [1, maxVal]
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int divisor = -1;

        while(left <= right)
        {
            // divisor
            int mid = left + (right - left)/2;

            long long int pieces = 0;
            for(int quantity: quantities)
            {
                // round-up division
                pieces += quantity % mid == 0 ? quantity/mid : quantity/mid + 1;
                if(pieces > n)
                    break;
            }

            if(pieces <= n)
            {
                divisor = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return divisor;
    }
};
// prerequisite: [1283. find-the-smallest-divisor-given-a-threshold]
// similar: [1870. minimum-speed-to-arrive-on-time]