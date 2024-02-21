class Solution {
public:
    bool checkIfExist(vector<int>& arr) { // T.C.=O(n^2), S.C.=O(1)
        int n=arr.size();
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(arr[i] == 2*arr[j] || arr[j] == 2*arr[i])
                    return true;
        return false;
    }
};