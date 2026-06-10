class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        // num -> {present in nums1, present in nums2}
        unordered_map<int, pair<bool, bool>> mp; 

        // mark the numbers present in nums1
        for(int num: nums1)
            mp[num] = {true, false};

        // mark the numbers present in nums2
        for(int num: nums2)
        {
            if(mp.find(num) != mp.end()) // found in map
                mp[num].second = true;
            else
                mp[num] = {false, true};
        }

        // count the numbers present only in nums1 (at max n/2)
        int n=nums1.size();
        int count1 = 0;
        for(auto it: mp)
        {
            if(count1 == n/2)
                break;
            auto [found1, found2] = it.second;
            if(found1 && !found2)
                count1++;
        }

        // count the numbers present only in nums2 (at max n/2)
        int count2 = 0;
        for(auto it: mp)
        {
            if(count2 == n/2)
                break;
            auto [found1, found2] = it.second;
            if(!found1 && found2)
                count2++;
        }

        // count the numbers present in both nums1 and nums2 
        // (without the total exceeding n)
        int count12 = 0;
        for(auto it: mp)
        {
            if(count1 + count2 + count12 == n)
                break;
            auto [found1, found2] = it.second;
            if(found1 && found2)
                count12++;
        }
        
        return count1 + count2 + count12;
    }
};