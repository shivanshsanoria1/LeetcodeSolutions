class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(101)
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> isFound(101, false);
        vector<int> ans(2, 0);
        // mark the num found in nums2[]
        for(int num: nums2)
            isFound[num] = true;
        // find the num in nums1[] which are also in nums2[]
        for(int num: nums1)
            if(isFound[num])
                ans[0]++;
        // reset the isFound[]
        for(int i=1; i<=100; i++)
            isFound[i] = false;
        // mark the num found in nums1[]
        for(int num: nums1)
            isFound[num] = true;
        // find the num in nums2[] which are also in nums1[]
        for(int num: nums2)
            if(isFound[num])
                ans[1]++;
        return ans;
    }
};