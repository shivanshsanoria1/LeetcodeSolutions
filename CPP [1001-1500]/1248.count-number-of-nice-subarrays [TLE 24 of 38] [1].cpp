class Solution {
public:
    // T.C.=O(n^2), S.C=O(1)
    int numberOfSubarrays(vector<int>& nums, int k) { 
        int n=nums.size();
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            int oddCount = 0;

            for(int j=i; j<n; j++)
            {
                if(nums[j] % 2 == 1)
                    oddCount++;

                if(oddCount == k)
                    ans++;
                else if(oddCount > k)
                    break;
            }
        }
        
        return ans;
    }
};