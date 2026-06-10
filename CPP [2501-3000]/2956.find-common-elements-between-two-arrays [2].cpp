class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(n1 + n2)
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> ans(2, 0);

        for(int num: nums1)
            if(s2.find(num) != s2.end()) // num found in set2
                ans[0]++;

        for(int num: nums2)
            if(s1.find(num) != s1.end()) // num found in set1
                ans[1]++;

        return ans;
    }
};