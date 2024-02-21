class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) { // T.C.=O(n*logn), S.C.=O(1)
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for(int i=2; i<arr.size(); i++)
            if(arr[i] - arr[i-1] != diff) // curr diff != 1st diff
                return false;
        return true;
    }
};