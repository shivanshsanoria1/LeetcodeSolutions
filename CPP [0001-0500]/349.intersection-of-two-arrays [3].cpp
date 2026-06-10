class Solution {
public:
    // T.C.=O(n1*logn1 + n2*logn2), S.C.=O(n1 + n2)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        auto itr1 = s1.begin(), itr2 = s2.begin();
        vector<int> ans;
        while(itr1 != s1.end() && itr2 != s2.end())
        {
            if(*itr1 == *itr2)
            {
                ans.push_back(*itr1);
                itr1++;
                itr2++;
            }
            else if(*itr1 < *itr2)
                itr1++;
            else
                itr2++;
        }
        return ans;
    }
};
