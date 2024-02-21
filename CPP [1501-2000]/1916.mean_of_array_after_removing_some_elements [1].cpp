class Solution {
public:
    double trimMean(vector<int>& arr) { // T.C.=O(n*logn),  S.C.=O(1)
        double avg = 0;
        int n = arr.size();
        int n5 = n/20; // 5% of n
        sort(arr.begin(), arr.end());
        for(int i=n5; i < n-n5; i++) // skip the first n5 and the last n5 elements
            avg += arr[i];
        avg /= (n - 2*n5);
        return avg;
    }
};