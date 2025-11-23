class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(n2) where n1 > n2
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        unordered_set<int> s;
        for(int i=0; i<nums1.size(); i++)
            for(int j=0; j<nums2.size(); j++)
                if(nums1[i] == nums2[j])
                    s.insert(nums1[i]);
                    
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};
