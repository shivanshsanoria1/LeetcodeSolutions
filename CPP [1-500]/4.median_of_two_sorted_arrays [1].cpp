class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { //T.C.=O(m+n) , S.C.=O(m+n)
        int m=nums1.size(), n=nums2.size();
        vector<int> merged;
        int i=0, j=0;
        while(i<m && j<n) //while there are elements in both vectors nums1 and nums2
        {
            if(nums1[i] <= nums2[j])
            {
                merged.push_back(nums1[i]);   
                i++;
            }
            else
            {
                merged.push_back(nums2[j]);   
                j++;
            }
        }
        while(i<m) //elements are remaining in vector nums1
        {
            merged.push_back(nums1[i]);   
            i++;
        }
        while(j<n) //elements are remaining in vector nums2
        {
            merged.push_back(nums2[j]);   
            j++;
        }
        int mid= (m+n)/2;
        return (m+n)%2==0 ? (merged[mid-1] + merged[mid])/2.0 : merged[mid];
    }
};