class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        vector<int> ans;
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        auto it1=s1.begin(), it2=s2.begin();
        while(it1 != s1.end() && it2 != s2.end())
        {
            if(*it1 == *it2)
            {
                ans.push_back(*it1);
                it1++;
                it2++;
            }
            else if(*it1 < *it2)
                it1++;
            else
                it2++;
        }
        return ans;
    }
};
// T.C.=O(n1*logn1 + n2*logn2), S.C.=O(n1 + n2) where n1 > n2