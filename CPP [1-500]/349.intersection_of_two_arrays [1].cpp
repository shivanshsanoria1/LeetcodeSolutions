class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        int n1=nums1.size(), n2=nums2.size();
        unordered_set<int> s;
        for(int i=0; i<n1; i++)
            for(int j=0; j<n2; j++)
                if(nums1[i] == nums2[j])
                    s.insert(nums1[i]);
        vector<int> ans;
        for(auto it: s)
            ans.push_back(it);
        return ans;
    }
};
// T.C.=O(n1*n2), S.C.=O(n2) where n1 > n2