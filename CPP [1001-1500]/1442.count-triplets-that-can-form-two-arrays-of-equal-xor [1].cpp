class Solution {
public:
    // T.C.=O(n^3), S.C.=O(1)
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int count = 0;

        for(int i=0; i<n-1; i++)
        {
            int a = 0;

            for(int j=i+1; j<n; j++)
            {
                a ^= arr[j-1];
                int b = 0;
                
                for(int k=j; k<n; k++)
                {
                    b ^= arr[k];
                    if(a == b)
                        count++;
                }
            }
        }

        return count;
    }
};