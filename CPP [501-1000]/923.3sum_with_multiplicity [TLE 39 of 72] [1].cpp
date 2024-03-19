class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n^3), S.C.=O(1)
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        int count = 0;

        for(int i=0; i<n-2; i++)
        {
            if(arr[i] > target)
                continue;
                
            for(int j=i+1; j<n-1; j++)
            {
                if(arr[i] + arr[j] > target)
                    continue;

                for(int k=j+1; k<n; k++)
                    if(arr[i] + arr[j] + arr[k] == target)
                        count = (count + 1) % MOD;
            }
        }
        
        return count;
    }
};