class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) { // T.C.=O(n^3), S.C.=O(1)
        int n=arr.size();
        int count = 0;
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
            {
                if(abs(arr[i] - arr[j]) > a)
                    continue;
                for(int k=j+1; k<n; k++)
                    if(abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c)
                        count++;
            }
        return count;
    }
};