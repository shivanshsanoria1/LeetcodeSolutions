class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) { // DP, T.C.=O(n1*n2), S.C.=O(min(n1, n2))
        if(nums2.size() > nums1.size())
            swap(nums1, nums2);
        int n1=nums1.size(), n2=nums2.size();
        vector<int> prevDP(n2+1, 0);
        int ans = 0;
        for(int i=1; i<=n1; i++)
        {
            vector<int> currDP(n2+1, 0);
            for(int j=1; j<=n2; j++)
                if(nums1[i-1] == nums2[j-1])
                {
                    currDP[j] = 1 + prevDP[j-1];
                    ans = max(ans, currDP[j]);
                }
            for(int j=0; j<=n2; j++)
                prevDP[j] = currDP[j];
        }
        return ans;
    }
};
// take steps to make sure length of nums1[] >= length of nums2[]