class Solution {
public:
    int findSpecialInteger(vector<int>& arr) { // T.C.=O(n), S.C.=O(1)
        int n=arr.size();
        int freq = 1;
        for(int i=1; i<n; i++)
        {
            if(arr[i] == arr[i-1]) // increment freq
                freq++;
            else // reset freq
                freq = 1;
            if(freq >= n/4 + 1) // curr freq >= required freq
                return arr[i];
        }
        return arr[0]; // array only has 1 element
    }
};