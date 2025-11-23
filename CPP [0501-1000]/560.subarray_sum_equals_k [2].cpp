class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int subarraySum(vector<int>& nums, int k) { 
        int count = 0;
        int currSum = 0;
        unordered_map<int, int> mp; // currSum -> freq
        for(int num: nums)
        {
            currSum += num;
            if(currSum == k)
                count++;
            // add freq of (currSum - k) to count 
            count += mp[currSum - k];
            // increment freq of currSum in map 
            mp[currSum]++; 
        }
        return count;
    }
};