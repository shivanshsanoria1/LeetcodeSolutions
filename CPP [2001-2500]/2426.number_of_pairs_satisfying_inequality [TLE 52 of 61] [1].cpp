class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums.size();
        long long int count = 0;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if((nums1[i] - nums2[i]) - (nums1[j] - nums2[j]) <= diff)
                    count++;
        
        return count;
    }
};