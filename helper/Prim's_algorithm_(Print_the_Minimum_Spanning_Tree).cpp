#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

typedef pair<int, int> PII;

int minimumSpanningTree(int V, vector<vector<PII>>& graph, vector<vector<int>>& mst){
    vector<int> visited(V, false);
    // min-heap; {wt, curr, parent}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, -1});
    int sumMST = 0;
    
    while(!pq.empty())
    {
        int wt = pq.top()[0];
        int curr = pq.top()[1];
        int parent = pq.top()[2];
        pq.pop();
        
        if(visited[curr])
            continue;
            
        visited[curr] = true;
        sumMST += wt;
        if(parent != -1)
            mst.push_back({curr, parent, wt});
        
        for(auto [nei, wt]: graph[curr])
        {
            if(visited[nei])
                continue;
            pq.push({wt, nei, curr});
        }
    }
    
    return sumMST;
}

// --------------- END --------------- //

int main() {
    int V = 5;
    // weighted undirected edge: {a, b, wt}: a--b of weight wt
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
    
    vector<vector<int>> mst;
    int sumMST = minimumSpanningTree(V, graph, mst);
    
    cout<<"MST weight = "<<sumMST<<endl;
    cout<<"MST is: "<<endl;
    cout<<"Edge  | Weight"<<endl;
    for(vector<int>& edge: mst)
    {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        
        if(a > b)
            swap(a, b);
        cout<<a<<" - "<<b<<" | "<<wt<<endl;
    }
    
    cout<<endl<<"--------------------"<<endl;

    return 0;
}