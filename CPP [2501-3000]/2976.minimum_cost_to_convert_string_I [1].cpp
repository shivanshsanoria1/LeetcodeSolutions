class Solution {
private:
    #define INF int(1e9)

public:
    // T.C.=O(n + m + 26^3), S.C.=O(26^2)
    // n: length of 'source' and 'target' strings
    // m: size of original[], changed[], cost[]
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // build adjacency matrix
        vector<vector<int>> graph(26, vector<int>(26, INF));
        
        for(int i=0; i<26; i++)
            graph[i][i] = 0;

        for(int i=0; i<original.size(); i++)
        {
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            int wt = cost[i];
            graph[a][b] = min(graph[a][b], wt);
        }

        // Floyd-Warshall
        for(int via=0; via<26; via++)
            for(int i=0; i<26; i++)
                for(int j=0; j<26; j++)
                    graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
        
        long long int totalCost = 0;
        for(int i=0; i<source.length(); i++)
        {
            if(source[i] == target[i])
                continue;
            if(graph[source[i] - 'a'][target[i] - 'a'] == INF)
                return -1;
            totalCost += graph[source[i] - 'a'][target[i] - 'a'];
        }

        return totalCost;
    }
};
// while building the adjacency-matrix 
// graph[a][b] = min(graph[a][b], wt) is used instead of 
// graph[a][b] = wt to avoid duplicate edges