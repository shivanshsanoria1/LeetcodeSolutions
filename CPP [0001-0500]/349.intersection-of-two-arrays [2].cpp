class Solution {
public:
    // T.C.=O(n1*logn1 + n2*logn2), S.C.=O(n2) where n1 > n2
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        unordered_set<int> s;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                s.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};
