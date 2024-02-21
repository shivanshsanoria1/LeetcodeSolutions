class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) { //T.C.=O(n^3)
        int n=arr.size(), total_sum=0, curr_sum;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j=j+2)
            {
                curr_sum=0;
                for(int k=i; k<=j; k++)
                    curr_sum+=arr[k];
                total_sum += curr_sum;
            }
        }
        return total_sum;
    }
};