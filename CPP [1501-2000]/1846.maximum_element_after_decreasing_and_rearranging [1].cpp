class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) { // T.C.=O(n*logn), S.C.=O(1)
        sort(arr.begin(), arr.end());
        if(arr[0] > 1)
            arr[0] = 1;
        int n=arr.size();
        for(int i=1; i<n; i++)
            if(arr[i] - arr[i-1] > 1)
                arr[i] = arr[i-1] + 1;
        return arr[n-1];
    }
};
// with modifying the input array