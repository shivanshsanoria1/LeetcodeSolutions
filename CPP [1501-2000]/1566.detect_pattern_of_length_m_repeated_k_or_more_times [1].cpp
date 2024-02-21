class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) { // T.C.=O(n^2), S.C.=O(1)
        if(arr.size() < m*k)
            return false;
        for(int i=0; i <= arr.size() - m*k; i++)
        {
            int idx = i;
            bool found = true;
            for(int j=i; j < i + m*k; j++)
            {
                if(arr[j] != arr[idx])
                {
                    found = false;
                    break;
                }

                idx++;
                if(idx >= i + m)
                    idx = i;
            }
            if(found)
                return true;
        }
        return false;
    }
};