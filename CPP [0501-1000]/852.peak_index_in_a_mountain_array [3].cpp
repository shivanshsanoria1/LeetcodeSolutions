class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) { // T.C.=O(logn), S.C.=O(1)
        int n=arr.size();
        int left = 1, right = n-2;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid-1] < arr[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};