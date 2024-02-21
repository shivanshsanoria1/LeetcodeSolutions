/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int bfs(unordered_map<int, vector<int>>& graph, int v){
        unordered_set<int> visited;
        queue<int> q;
        visited.insert(v);
        q.push(v);
        int level = -1;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            while(size--)
            {
                int a = q.front();
                q.pop();
                for(int b: graph[a])
                {
                    if(visited.find(b) != visited.end()) // node 'b' found in set
                        continue;
                    visited.insert(b);
                    q.push(b);
                }
            }
        }
        return level;
    }

    void buildGraph(unordered_map<int, vector<int>>& graph, TreeNode* curr, int parVal){
        if(curr == NULL)
            return;
        if(parVal != -1) // parent val exists
        {
            graph[curr->val].push_back(parVal);
            graph[parVal].push_back(curr->val);
        }
        buildGraph(graph, curr->left, curr->val);
        buildGraph(graph, curr->right, curr->val);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        buildGraph(graph, root, -1);
        return bfs(graph, start);
    }
};
/*
# step 1: build a graph, ie, adjacency list from the given binary tree
# step 2: use BFS from the 'start' node in the graph to find the number of levels 
required to visit all the nodes
*/