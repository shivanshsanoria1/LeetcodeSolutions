class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) { // T.C.=O(n), S.C.=O(n)
        int n=arr.size();
        // keeps track of elements which are peak from the left side
        vector<bool> isPeakLeft(n, false);
        // keeps track of elements which are peak from the right side
        vector<bool> isPeakRight(n, false);
        // assume arr[0] to be a left-peak even though it isn't
        isPeakLeft[0] = true; 
        for(int i=1; i<n; i++)
            if(isPeakLeft[i-1] && arr[i-1] < arr[i])
                isPeakLeft[i] = true;
        // assume arr[n-1] to be a right-peak even though it isn't
        isPeakRight[n-1] = true; 
        for(int i=n-2; i>=0; i--)
            if(isPeakRight[i+1] && arr[i] > arr[i+1])
                isPeakRight[i] = true;
        // return the index which is a peak from both left and right sides
        // also, index 0 and n-1 cannot be the peak
        for(int i=1; i<n-1; i++)
            if(isPeakLeft[i] && isPeakRight[i])
                return i;
        return -1;
    }
};