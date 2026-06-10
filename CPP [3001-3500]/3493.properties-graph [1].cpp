class Solution {
private:
    int countDistinctIntersections(vector<bool>& isPresent1, vector<int>& nums2){
        vector<bool> isPresent2(101, false);
        for(int num: nums2)
            isPresent2[num] = true;
        
        int count = 0;
        for(int i=1; i<=100; i++)
            if(isPresent1[i] && isPresent2[i])
                count++;
        
        return count;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return;
        
        visited[curr] = true;

        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }

public:
    // T.C.=O(), S.C.=O()
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size(), m = properties[0].size();
        vector<vector<int>> graph(n);

        for(int i=0; i<n; i++)
        {
            vector<bool> isPresent1(101, false);
            for(int num: properties[i])
                isPresent1[num] = true;

            for(int j=0; j<n; j++)
            {
                if(i == j)
                    continue;
                if(countDistinctIntersections(isPresent1, properties[j]) < k)
                    continue;

                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }

        int components = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++)
        {
            if(visited[i])
                continue;
            
            components++;
            dfs(graph, visited, i);
        }
        
        return components;
    }
};