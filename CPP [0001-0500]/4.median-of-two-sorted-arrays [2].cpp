class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { //T.C.=O(m+n) , S.C.=O(1)
        int m=nums1.size(), n=nums2.size();
        int mid=(m+n)/2;
        int i=0, j=0;
        int prev, curr;
        while(mid>=0 && i<m && j<n) //while there are elements in both vectors nums1 and nums2
        {
            if(nums1[i] <= nums2[j])
            {
                prev=curr;
                curr=nums1[i];
                i++;
            }
            else
            {
                prev=curr;
                curr=nums2[j];
                j++;
            }
            mid--;
        }
        while(mid>=0 && i<m) //elements are remaining in vector nums1
        {
            prev=curr;
            curr=nums1[i];
            i++;
            mid--;
        }
        while(mid>=0 && j<n) //elements are remaining in vector nums2
        {
            prev=curr;
            curr=nums2[j];
            j++;
            mid--;
        }
        return (m+n)%2==0 ? (prev + curr)/2.0 : curr;
    }
};