class Solution {
public:
    // T.C.=O(n1*log(n1) + n2*log(n2)), S.C.=O(1)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0, j = 0;
        while(i < g.size() && j < s.size())
        {
            if(g[i] <= s[j])
            {
                i++;
                count++;
            }
            j++;
        }
        return count;
    }
};