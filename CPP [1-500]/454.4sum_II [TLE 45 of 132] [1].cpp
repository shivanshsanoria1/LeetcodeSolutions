class Solution {
public:
    // T.C.=O(n^4), S.C.=O(1)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        int count = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    for(int l=0; l<n; l++)
                        if(nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0)
                            count++;
        return count;
    }
};