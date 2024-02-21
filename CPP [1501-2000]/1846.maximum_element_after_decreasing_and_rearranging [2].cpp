class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) { // T.C.=O(n*logn), S.C.=O(1)
        sort(arr.begin(), arr.end());
        int prev = 0;
        for(int num: arr)
            prev = min(prev + 1, num);
        return prev;
    }
};
// without modifying the input array