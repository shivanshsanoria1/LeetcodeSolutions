class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int majorityElement(vector<int>& nums) { 
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
        {
            mp[num]++;
            if(mp[num] > nums.size()/2)
                return num;
        }
        return -1;
    }
};