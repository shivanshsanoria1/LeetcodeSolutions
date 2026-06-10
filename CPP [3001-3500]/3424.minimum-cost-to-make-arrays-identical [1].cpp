class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        // cost without rearrangement
        long long int cost1 = 0;
        for(int i=0; i<arr.size(); i++)
            cost1 += abs(arr[i] - brr[i]);

        // sort both arrays to minimize the abs diff 
        // between each corresponding element
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        // cost with rearrangement
        long long int cost2 = k;
        for(int i=0; i<arr.size(); i++)
            cost2 += abs(arr[i] - brr[i]);
        
        return min(cost1, cost2);
    }
};