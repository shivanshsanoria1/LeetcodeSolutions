class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int evenCount = 0, oddCount = 0;
            int x = 0;
            for(int j=i; j<n; j++){
                if(nums[j] % 2 == 0)
                    evenCount++;
                else
                    oddCount++;

                x ^= nums[j];

                if(x == 0 && evenCount == oddCount)
                    maxLen = max(maxLen, j-i+1);
            }
        }

        return maxLen;
    }
};