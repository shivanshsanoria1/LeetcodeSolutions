class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) { // T.C.=O(n), S.C.=O(26)
        vector<int> indexes(26, -1);
        for(int i=0; i<s.length(); i++)
        {
            if(indexes[s[i] - 'a'] == -1)
            {
                indexes[s[i] - 'a'] = i;
                continue;
            }
            int prevIdx = indexes[s[i] - 'a'];
            indexes[s[i] - 'a'] = i;
            if(i - prevIdx - 1 != distance[s[i] - 'a'])
                return false;
        }
        return true;
    }
};