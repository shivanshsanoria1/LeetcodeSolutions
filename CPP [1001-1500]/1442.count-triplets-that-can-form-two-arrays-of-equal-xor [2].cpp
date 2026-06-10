class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countTriplets(vector<int>& arr) {    
        int n=arr.size();
        int count = 0;

        for(int i=0; i<n-1; i++)
        {
            int x = arr[i];
            for(int k=i+1; k<n; k++)
            {
                x ^= arr[k];
                if(x == 0)
                    count += (k-i+1) - 1;
            }
        }

        return count;
    }
};
/*
# for any triplet (i,j,k) where i < j <= k to be counted towards the ans
  xor in range [i,j-1] = xor in range [j,k]
  taking xor with { xor in range [j,k] } on both sides and using the property A^A = 0
  { xor in range [i,j-1] } xor { xor in range [j,k] } = 0
  xor in range [i,k] = 0
# thus we just need to find subarrays of type [i,k] where i < k 
  with xor = 0
# now for a subarray of type [i,k], where i < k  
  we can choose j at any index except i since i < j <= k
  so there are len(subarry[i,k]) - 1 choices for j
  len(subarry[i,k]) - 1 = (k-i+1) - 1 = k-i
*/