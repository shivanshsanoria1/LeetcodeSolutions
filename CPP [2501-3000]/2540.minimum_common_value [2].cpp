class Solution {
public:
    // T.C.=O(n1*logn2), S.C.=O(1), where n1 < n2
    // Binary-Search
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);

        for(int num: nums1)
        {
            int left = 0, right = nums2.size()-1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(nums2[mid] == num)
                    return num;
                else if(nums2[mid] < num)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};