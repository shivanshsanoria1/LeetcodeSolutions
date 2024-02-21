class Solution {
public:
    int partitionString(string s) { // Greedy, T.C.=O(n), S.C.=O(26)
        int count = 1;
        vector<bool> visited(26, false);
        for(char ch: s)
        {
            if(visited[ch - 'a'])
            {
                count++;
                // reset the visited vector for the next substring
                for(int i=0; i<26; i++) 
                    visited[i] = false;
            }
            visited[ch - 'a'] = true;
        }
        return count;
    }
};