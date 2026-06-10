/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // build an undirected acyclic graph
    void buildGraph(unordered_map<int, vector<int>>& graph, TreeNode* curr){ // DFS
        int currVal = curr->val;

        if(curr->left != NULL)
        {
            int leftVal = curr->left->val;
            graph[currVal].push_back(leftVal);
            graph[leftVal].push_back(currVal);
            buildGraph(graph, curr->left);
        }

        if(curr->right != NULL)
        {
            int rightVal = curr->right->val;
            graph[currVal].push_back(rightVal);
            graph[rightVal].push_back(currVal);
            buildGraph(graph, curr->right);
        }
    }
    
    vector<int> bfs(unordered_map<int, vector<int>>& graph, int targetVal, int k){
        queue<int> q;
        unordered_set<int> visited;
        visited.insert(targetVal); // mark the target node as visited
        q.push(targetVal);
        int dist = 0;
        while(!q.empty() && dist < k)
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                // check the nodes connected to the curr node
                for(int nei: graph[curr]) 
                    // unvisited neighbours of curr node
                    if(visited.find(nei) == visited.end())
                    {
                        visited.insert(nei); // mark the neighbour node as visited
                        q.push(nei);
                    }
            }
            dist++;
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
        }
        return ans;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph; // node -> {neighbour nodes}
        buildGraph(graph, root);
        return bfs(graph, target->val, k);
    }
};