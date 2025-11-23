class Solution {
public:
    // T.C.=O(n1*log(n1) + n2*log(n2)), S.C.=O(1)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { 
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        vector<int> ans;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else // nums1[i] > nums2[j]
                j++;
        }

        return ans;
    }
};