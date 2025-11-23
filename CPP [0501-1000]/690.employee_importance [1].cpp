/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    int dfs(unordered_map<int, vector<int>>& graph, unordered_map<int, int>& mp, unordered_set<int>& visited, int curr) {
        if(visited.find(curr) != visited.end())
            return 0;
        
        visited.insert(curr);

        int sum = mp[curr];
        for(int nei: graph[curr])
            sum += dfs(graph, mp, visited, nei);
        
        return sum;
    }

public:
    int getImportance(vector<Employee*> employees, int id) {
        // employeeId -> importance
        unordered_map<int, int> mp;
        // employeeId -> { subordinateId }
        unordered_map<int, vector<int>> graph;

        for(Employee* employee: employees)
        {
            int id = employee->id;
            int importance = employee->importance;
            vector<int>& subordinates = employee->subordinates;

            mp[id] = importance;

            for(int subordinateId: subordinates)
                graph[id].push_back(subordinateId);
        }

        unordered_set<int> visited;

        return dfs(graph, mp, visited, id);
    }
};