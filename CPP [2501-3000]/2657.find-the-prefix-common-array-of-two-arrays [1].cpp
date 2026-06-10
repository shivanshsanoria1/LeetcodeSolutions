class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<bool> foundA(n+1, false);
        vector<bool> foundB(n+1, false);

        vector<int> commons(n, 0);
        for(int i=0; i<n; i++)
        {
            foundA[A[i]] = true;
            foundB[B[i]] = true;

            for(int j=1; j<=n; j++)
                if(foundA[j] && foundB[j])
                    commons[i]++;
        }

        return commons;
    }
};