class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(), m=potions.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<m; j++)
                if((long long int)spells[i] * potions[j] >= success)
                    count++;
            ans[i] = count;
        }
        return ans;
    }
};
// T.C.=O(n*m), S.C.=O(1)