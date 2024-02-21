class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { //T.C.=O(n^2) , S.C.=O(n)
        int n=nums.size();
        vector<int> nums2(2*n); //nums2[] is nums[] concatenated 2 times
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++)
        {
            nums2[i]= nums[i];
            nums2[i+n]= nums[i];
        }
        for(int i=0; i<n; i++)
            for(int j=i+1; j<2*n; j++)
                if(nums2[j] > nums2[i]) //NGE found for nums2[i]
                {
                    ans[i]= nums2[j];
                    break;
                }
        return ans;
    }
};