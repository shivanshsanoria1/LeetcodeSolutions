## What its about ?

Dijkstra’s algorithm is a popular algorithms for solving many single-source shortest path problems having non-negative edge weight in the graphs i.e., it is to find the shortest distance between two vertices on a graph.

The algorithm maintains a set of visited vertices and a set of unvisited vertices. It starts at the source vertex and iteratively selects the unvisited vertex with the smallest tentative distance from the source. It then visits the neighbors of this vertex and updates their tentative distances if a shorter path is found. This process continues until the destination vertex is reached, or all reachable vertices have been visited.

---

### Can Dijkstra’s Algorithm work on both Directed and Undirected graphs? 

Yes, Dijkstra’s algorithm can work on both directed graphs and undirected graphs as this algorithm is designed to work on any type of graph as long as it meets the requirements of having non-negative edge weights and being connected.

* In a directed graph, each edge has a direction, indicating the direction of travel between the vertices connected by the edge. In this case, the algorithm follows the direction of the edges when searching for the shortest path.

* In an undirected graph, the edges have no direction, and the algorithm can traverse both forward and backward along the edges when searching for the shortest path.

---

### Steps:

1. Mark the source node with a current distance of 0 and the rest with infinity.
1. Set the non-visited node with the smallest current distance as the current node.
1. For each neighbor, N of the current node adds the current distance of the adjacent node with the weight of the edge connecting 0->1. If it is smaller than the current distance of Node, set it as the new current distance of N.
1. Mark the current node 1 as visited.
1. Go to step 2 if there are any nodes are unvisited.

---

### Time Complexity = O((V + E)*log(V))
### Space Complexity = O(V)
#### V: number of vertices
#### E: number of edges

---

## Dijkstra’s Algorithms vs Bellman-Ford Algorithm

Feature | Dijkstra’s | 	Bellman Ford
--- | --- | ---
Optimization | optimized for finding the shortest path between a single source node and all other nodes in a graph with non-negative edge weights | Bellman-Ford algorithm is optimized for finding the shortest path between a single source node and all other nodes in a graph with negative edge weights.
Relaxation | Dijkstra’s algorithm uses a greedy approach where it chooses the node with the smallest distance and updates its neighbors | the Bellman-Ford algorithm relaxes all edges in each iteration, updating the distance of each node by considering all possible paths to that node
Time Complexity | Dijkstra’s algorithm has a time complexity of O(V^2) for a dense graph and O(E log V) for a sparse graph, where V is the number of vertices and E is the number of edges in the graph. | Bellman-Ford algorithm has a time complexity of O(VE), where V is the number of vertices and E is the number of edges in the graph.
Negative Weights | Dijkstra’s algorithm does not work with graphs that have negative edge weights, as it assumes that all edge weights are non-negative. | Floyd-Warshall algorithm, on the other hand, is an all-pairs shortest path algorithm that uses dynamic programming to calculate the shortest path between all pairs of nodes in the graph.

---
