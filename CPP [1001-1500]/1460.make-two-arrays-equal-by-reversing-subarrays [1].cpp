class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    bool canBeEqual(vector<int>& target, vector<int>& arr) { 
        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());

        return arr == target;
    }
};