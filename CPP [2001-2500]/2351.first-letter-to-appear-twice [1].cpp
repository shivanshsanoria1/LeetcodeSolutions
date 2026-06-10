class Solution {
public:
    // T.C.=O(26), S.C.=O(26)
    char repeatedCharacter(string s) {
        vector<bool> visited(26, false);
        for(char ch: s)
        {
            if(visited[ch - 'a'])
                return ch;
            else
                visited[ch - 'a'] = true;
        }

        // never executed; since string s is guranteed to 
        // contain at least one letter that appears twice
        return '#';
    }
};