class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) { // T.C.=O(n^2), S.C.=O(26)
        int n=s.length();
        vector<bool> seen(26, false);
        for(int i=0; i<n-1; i++)
        {
            if(seen[s[i] - 'a'])
                continue;
            for(int j=i+1; j<n; j++)
            {
                if(s[j] != s[i])
                    continue;
                if(j-i-1 != distance[s[i] - 'a'])
                    return false;
                else
                {
                    seen[s[i] - 'a'] = true;
                    break;
                }
            }
        }
        return true;
    }
};