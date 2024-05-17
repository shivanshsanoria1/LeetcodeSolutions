class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n^2)
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> s;

        for(int i=0; i<n; i++)
        {
            int subarrayOR = 0;
            
            for(int j=i; j<n; j++)
            {
                subarrayOR |= arr[j];
                s.insert(subarrayOR);
            }
        }

        return s.size();
    }
};