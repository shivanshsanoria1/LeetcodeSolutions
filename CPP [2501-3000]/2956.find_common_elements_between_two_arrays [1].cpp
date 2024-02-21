class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(1)
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2, 0);

        for(int num1: nums1)
            for(int num2: nums2)
                if(num1 == num2)
                {
                    ans[0]++;
                    break;
                }

        for(int num2: nums2)
            for(int num1: nums1)
                if(num2 == num1)
                {
                    ans[1]++;
                    break;
                }

        return ans;
    }
};