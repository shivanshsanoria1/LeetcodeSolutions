class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        vector<int> ans;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        for(auto it1: s1)
            if(s2.find(it1) != s2.end()) // number it1 found in set s2
                ans.push_back(it1);
        return ans;
    }
};
// T.C.=O(n1 + n2), S.C.=O(n1 + n2)