class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { //T.C.=O(n1*n2) , S.C.=O(1)
        int n1=nums1.size(), n2=nums2.size();
        vector<int> ans;
        for(int i=0; i<n1; i++)
        {
            int j;
            for(j=0; j<n2; j++) //find nums1[i] in nums2 array
                if(nums1[i] == nums2[j])
                    break;
            for(j=j+1; j<n2; j++) //search to the right of the curr element in nums2 array
                if(nums2[j] > nums1[i]) //NGE found for nums1[i]
                {
                    ans.push_back(nums2[j]);
                    break;
                }
            if(j == n2) //NGE not found for nums1[i]
                ans.push_back(-1);
        }
        return ans;
    }
};