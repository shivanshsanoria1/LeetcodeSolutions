class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {// T.C.=O(n)
        int n=arr.size(), sum=0, freq;
        for(int i=0; i<n; i++)
        {
            freq=((n-i)*(i+1)+1)/2;
            sum += arr[i]*freq;
        }
        return sum;
    }
};