class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(1)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        int n2=nums2.size();
        vector<int> ans;

        for(int num1: nums1)
        {
            int i = -1;

            // find num1 in nums2[]
            for(i=0; i<n2; i++) 
                if(num1 == nums2[i])
                    break;

            // search for the NGE of num1 in nums2[]
            for(i=i+1; i<n2; i++) 
                if(nums2[i] > num1) 
                {
                    ans.push_back(nums2[i]);
                    break;
                }

            // NGE of num1 not found in nums2[]
            if(i == n2) 
                ans.push_back(-1);
        }

        return ans;
    }
};