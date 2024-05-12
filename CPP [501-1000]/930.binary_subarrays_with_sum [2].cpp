class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int numSubarraysWithSum(vector<int>& nums, int goal) { 
        // prefix sum -> freq
        unordered_map<int, int> mp;

        int prefixSum = 0;
        int count = 0;

        for(int num: nums)
        {
            prefixSum += num;

            if(prefixSum == goal)
                count++;
                
            count += mp[prefixSum - goal];
            
            mp[prefixSum]++;
        }

        return count;
    }
};