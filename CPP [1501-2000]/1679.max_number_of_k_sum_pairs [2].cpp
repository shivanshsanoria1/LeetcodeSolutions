class Solution {
public:
    int maxOperations(vector<int>& nums, int k) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> mp; // num -> freq
        int count = 0;
        for(int num: nums)
        {
            if(mp[k - num] > 0) // (k - num) found in map
            {
                count++;
                mp[k - num]--;
            }
            else
                mp[num]++;
        } 
        return count;
    }
};