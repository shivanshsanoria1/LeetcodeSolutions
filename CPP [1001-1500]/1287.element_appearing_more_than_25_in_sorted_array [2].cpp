class Solution {
public:
    int findSpecialInteger(vector<int>& arr) { // T.C.=O(n), S.C.=O(1)
        int n=arr.size();
        for(int i=0; i < n - n/4; i++)
            if(arr[i] == arr[i + n/4])
                return arr[i];
        return -1;
    }
};