#include <bits/stdc++.h>
 
#define INF INT_MAX
typedef pair<int, int> PI;

vector<int> dijkstra(vector<vector<int>> &edges, int V, int E, int src) 
{
	// Write your code here
	// 'edge' contains {u, v, distance} vectors

	// Return a vector of size 'vertices' denoting 
	// distances of source node to every node
	vector<vector<PI>> graph(V);
	for(auto& edge: edges) // build graph
	{
		int a = edge[0];
		int b = edge[1];
		int wt = edge[2];
		graph[a].push_back({b, wt});
		graph[b].push_back({a, wt});
	}
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
	pq.push({dist[src], src});
	while(!pq.empty())
	{
		//int dis = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		for(auto it: graph[curr])
		{
			int nei = it.first;
			int wt = it.second;
			if(dist[curr] + wt < dist[nei])
			{
				dist[nei] = dist[curr] + wt;
				pq.push({dist[nei], nei});
			}
		}
	}
	return dist;
}

/*
# T.C.=O(E*logV), S.C.=O(V^2)
# may not work with -ive edge weights
# definitely not work when there is a -ive weight cycle
# based on Greedy approach
*/