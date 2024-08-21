class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> lastIdx(26, -1);
        for(int i=n-1; i>=0; i--)
            if(lastIdx[s[i] - 'a'] == -1)
                lastIdx[s[i] - 'a'] = i;

        // size of curr partition
        int size = 0;
        // end index of curr partition
        int end = -1;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            end = max(end, lastIdx[s[i] - 'a']);
            size++;
            
            if(i == end)
            {
                ans.push_back(size);
                size = 0;
                end = -1;
            }
        }

        return ans;
    }
};