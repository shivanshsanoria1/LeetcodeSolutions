class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    vector<int> nextGreaterElements(vector<int>& nums) { 
        int n=nums.size();
        // nums2[] is nums[] concatenated 2 times
        vector<int> nums2(2*n); 
        for(int i=0; i<n; i++)
        {
            nums2[i] = nums[i];
            nums2[i+n] = nums[i];
        }

        vector<int> nge(n, -1);
        for(int i=0; i<n; i++)
            for(int j=i+1; j<2*n; j++)
                if(nums2[j] > nums2[i])
                {
                    nge[i] = nums2[j];
                    break;
                }

        return nge;
    }
};