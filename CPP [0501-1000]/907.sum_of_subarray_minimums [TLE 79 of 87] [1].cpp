class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n^2), S.C.=O(1)
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            int minVal = INT_MAX;
            for(int j=i; j<n; j++)
            {
                minVal = min(minVal, arr[j]);
                sum = (sum + minVal) % MOD;
            }
        }
        return sum;
    }
};