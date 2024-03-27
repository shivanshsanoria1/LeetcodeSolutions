class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // (num1 + num2) -> freq
        unordered_map<int, int> mp12;
        // (num3 + num4) -> freq
        unordered_map<int, int> mp34;

        int n=nums1.size();

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                mp12[nums1[i] + nums2[j]]++;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                mp34[nums3[i] + nums4[j]]++;
        
        int count = 0;
        for(auto [num12, freq12]: mp12)
            count += freq12 * mp34[-num12];

        return count;
    }
};