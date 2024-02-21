class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { // T.C.=O(n1 + n2), S.C.=O(n1)
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums1)
            mp[num]++;
        vector<int> ans;
        for(int num: nums2)
            if(mp[num] > 0)
            {
                ans.push_back(num);
                mp[num]--;
            }
        return ans;
    }
};