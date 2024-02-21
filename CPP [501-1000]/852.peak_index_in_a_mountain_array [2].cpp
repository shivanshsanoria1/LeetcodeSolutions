class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) { // T.C.=O(n), S.C.=O(1)
        for(int i=1; i<arr.size()-1; i++)
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1])
                return i;
        return -1;
    }
};