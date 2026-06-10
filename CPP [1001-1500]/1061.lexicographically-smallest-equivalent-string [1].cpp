class Solution {
private:
    void dfs(unordered_map<char, vector<char>>& graph, vector<bool>& visited, char curr){
        if(visited[curr - 'a'])
            return;
        
        visited[curr - 'a'] = true;

        for(char nei: graph[curr])
            dfs(graph, visited, nei);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> graph;

        for(int i=0; i<s1.length(); i++)
        {
            // ignore the self-edges
            if(s1[i] == s2[i])
                continue;
            graph[s1[i]].push_back(s2[i]);
            graph[s2[i]].push_back(s1[i]);
        }

        // lexicographically smallest equivalent char for each char
        vector<char> lexiSmallestChar(26, '#');

        string ans = "";

        for(char ch: baseStr)
        {
            // char not found in map, ie, char is its own
            // lexicographically smallest equivalent char
            if(graph.find(ch) == graph.end())
            {
                ans += ch;
                continue;
            }

            // solution already precomputed, 
            // so no need to run dfs() again
            if(lexiSmallestChar[ch - 'a'] != '#')
            {
                ans += lexiSmallestChar[ch - 'a'];
                continue;
            }

            vector<bool> visited(26, false);

            dfs(graph, visited, ch);

            // the smallest char visited during dfs() (starting at curr char)
            // is its lexicographically smallest equivalent char
            for(int i=0; i<26; i++)
                if(visited[i])
                {
                    lexiSmallestChar[ch - 'a'] = char('a' + i);
                    break;
                }
            
            ans += lexiSmallestChar[ch - 'a'];
        }

        return ans;
    }
};