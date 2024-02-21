class Solution {
public:
    bool checkIfExist(vector<int>& arr) { // T.C.=O(n^2), S.C.=O(1)
        int n=arr.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    continue;
                if(arr[i] == 2*arr[j])
                    return true;
            }
        return false;
    }
};