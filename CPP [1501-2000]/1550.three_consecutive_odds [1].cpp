class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=2; i<arr.size(); i++)
            if(arr[i-2] % 2 == 1 && arr[i-1] % 2 == 1 && arr[i] % 2 == 1)
                return true;

        return false;
    }
};