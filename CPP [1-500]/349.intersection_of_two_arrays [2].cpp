class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        int n1=nums1.size(), n2=nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> s;
        int i=0, j=0;
        while(i < n1 && j < n2)
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
        vector<int> ans;
        for(auto it: s)
            ans.push_back(it);
        return ans;
    }
};
// T.C.=O(n1*logn1 + n2*logn2), S.C.=O(n2) where n1 > n2