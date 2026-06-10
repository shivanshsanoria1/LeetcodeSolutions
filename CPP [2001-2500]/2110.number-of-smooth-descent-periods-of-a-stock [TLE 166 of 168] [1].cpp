class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        // each subarray of size 1 is also considered valid
        long long int count = n;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                if(prices[j-1] - prices[j] != 1)
                    break;
                count++;
            }
        
        return count;
    }
};