class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n^2), S.C.=O(1)
    int numOfSubarrays(vector<int>& arr) { 
        int n=arr.size();
        int count = 0;

        for(int i=0; i<n; i++)
        {
            int sum = 0;

            for(int j=i; j<n; j++)
            {
                sum += arr[j];

                if(sum % 2 == 1)
                    count = (count + 1) % MOD;
            }
        }

        return count;
    }
};