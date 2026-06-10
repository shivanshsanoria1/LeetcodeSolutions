class Solution {
public:
    int countKDifference(vector<int>& nums, int k) { // T.C=O(n), S.C.=O(n)
        int count = 0;
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
        {// for each element check if (num + k) or (num - k) is present in map, 
         // if present then add their freq to ans 
            if(mp.find(num + k) != mp.end())
                count += mp[num + k];
            if(mp.find(num - k) != mp.end())
                count += mp[num - k];
            mp[num]++; // add each element and their freq in map
        }
        return count;
    }
};