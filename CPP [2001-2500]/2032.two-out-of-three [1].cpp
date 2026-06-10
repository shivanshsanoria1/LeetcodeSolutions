class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) { //T.C.=O(n^2) , S.C.=O(n)
        vector<int> ans;
        int n1=nums1.size(), n2=nums2.size(), n3=nums3.size();
        unordered_set<int> s;
        for(int i=0; i<n1; i++) //find common elements between nums1 and nums2
            for(int j=0; j<n2; j++)
                if(nums1[i] == nums2[j])
                    s.insert(nums1[i]);
        for(int i=0; i<n2; i++) //find common elements between nums2 and nums3
            for(int j=0; j<n3; j++)
                if(nums2[i] == nums3[j])
                    s.insert(nums2[i]);
        for(int i=0; i<n3; i++) //find common elements between nums3 and nums1
            for(int j=0; j<n1; j++)
                if(nums3[i] == nums1[j])
                    s.insert(nums3[i]);
        for(auto it: s)
            ans.push_back(it);
        return ans;
    }
};