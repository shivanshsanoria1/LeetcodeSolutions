class Solution {
public:
    int partitionString(string s) { // Greedy, T.C.=O(n), S.C.=O(26)
        int count = 1;
        unordered_set<char> visited;
        for(char ch: s)
        {
            if(visited.find(ch) != visited.end()) // char ch found in set
            {
                count++;
                // clear the visited set for the next substring
                visited.clear();
            }
            visited.insert(ch);
        }
        return count;
    }
};