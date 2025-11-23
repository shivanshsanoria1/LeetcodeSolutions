class Solution {
public:
    // T.C.=O(n^3), S.C.=O(n)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // num4 -> freq
        unordered_map<int, int> mp;
        for(int num: nums4)
            mp[num]++;

        int n=nums1.size();
        int count = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    count += mp[-(nums1[i] + nums2[j] + nums3[k])];
        return count;
    }
};