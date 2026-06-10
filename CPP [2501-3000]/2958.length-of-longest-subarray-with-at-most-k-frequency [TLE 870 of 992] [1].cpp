class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLen = 0;
        int n=nums.size();
        
        for(int i=0; i<n; i++)
        {
            // num -> freq
            unordered_map<int, int> mp;

            for(int j=0; j<n; j++)
            {
                mp[nums[j]]++;

                if(mp[nums[j]] > k)
                    break;

                maxLen = max(maxLen, j-i+1);
            }
        }

        return maxLen;
    }
};