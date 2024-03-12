class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(n1 + n2)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> ans;
        for(int num: s1)
            // 'num' found in set2
            if(s2.find(num) != s2.end())
                ans.push_back(num);
        return ans;
    }
};
