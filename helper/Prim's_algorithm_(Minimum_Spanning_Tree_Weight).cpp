#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

typedef pair<int, int> PII;

int minimumSpanningTree(int V, vector<vector<PII>>& graph){
    vector<int> visited(V, false);
    // min-heap; {wt, curr}
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 0});
    int sumMST = 0;
    
    while(!pq.empty())
    {
        auto [wt, curr] = pq.top();
        pq.pop();
        
        if(visited[curr])
            continue;
            
        visited[curr] = true;
        sumMST += wt;
        
        for(auto [nei, wt]: graph[curr])
        {
            if(visited[nei])
                continue;
            pq.push({wt, nei});
        }
    }
    
    return sumMST;
}

// --------------- END --------------- //

int main() {
    int V = 5;
    // edge: {a, b, wt}
    vector<vector<int>> edges = { {0,1,2}, {0,2,1}, {1,2,1}, {2,3,2}, {2,4,2}, {3,4,1} };
    
    vector<vector<PII>> graph(V);
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        
        graph[a].push_back({b, wt});
        graph[b].push_back({a, wt});
    }
    
    int sumMST = minimumSpanningTree(V, graph);
    
    cout<<"MST weight = "<<sumMST<<endl;
    
    cout<<"--------------------"<<endl;

    return 0;
}