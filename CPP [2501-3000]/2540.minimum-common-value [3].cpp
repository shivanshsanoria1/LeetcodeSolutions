class Solution {
private:
    // T.C.=O(n1 + n2), S.C.=O(1)
    // 2-pointer
    int solve_2Pointer(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
                return nums1[i];
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return -1;
    }

    // T.C.=O(n1*logn2), S.C.=O(1), where n1 < n2
    // Binary-Search
    int solve_BinarySearch(vector<int>& nums1, vector<int>& nums2) {
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

public:
    // T.C.=O(min(n1 + n2, n1*logn2)), S.C.=O(1), where n1 < n2
    // 2-pointer or Binary-Search
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if(n1 > n2)
            swap(n1, n2);

        return n1 + n2 < n1 * floor(log2(n2)) ? solve_2Pointer(nums1, nums2) : solve_BinarySearch(nums1, nums2);
    }
};