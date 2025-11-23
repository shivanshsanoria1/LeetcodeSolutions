class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) { // T.C.=O(n^2), S.C.=O(1)
        int n=arr.size();
        for(int i=1; i<n-1; i++)
        {
            int left = i-1, right = i+1;
            while(left >= 0 && arr[left] < arr[left+1])
                left--;
            if(left != -1)
                break;
            while(right < n && arr[right-1] > arr[right])
                right++;
            if(right == n)
                return i;
        }
        return -1;
    }
};