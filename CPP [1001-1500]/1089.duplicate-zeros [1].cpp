class Solution {
public:
    void duplicateZeros(vector<int>& arr) { //T.C.=O(n), S.C.=O(n)
        int n= arr.size();
        vector<int> vec(n,0);
        int i=0, j=0;
        while(i<n)
        {
            if(arr[j] != 0)
            {
                vec[i] = arr[j];
                i++;
            }
            else
                i += 2;
            j++;
        }
        for(int i=0; i<n; i++)
            arr[i] = vec[i];
    }
};