class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {// T.C.=O(n^2)
        int n=arr.size(), total_sum=0, curr_sum;
        for(int i=0; i<n; i++)
        {
            curr_sum=0;
            for(int j=i; j<n; j++)
            {
                curr_sum += arr[j];
                if(i%2 == j%2) // i and j have same parity
                    total_sum += curr_sum; // only add curr_sum to total_sum if i and j have same parity         
            }
        }
        return total_sum;
    }
};