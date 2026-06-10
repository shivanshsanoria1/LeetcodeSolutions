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
private:
    typedef pair<int, char> PIC;

    int countNodes(TreeNode* curr){
        if(curr == nullptr)
            return 0;

        int leftCount = countNodes(curr->left);
        int rightCount = countNodes(curr->right);

        return 1 + leftCount + rightCount;
    }

    void buildGraph(vector<vector<PIC>>& graph, TreeNode* curr, TreeNode* parent){
        if(curr == nullptr)
            return;
        
        if(parent != nullptr)
            graph[curr->val].push_back({parent->val, 'U'});
        
        if(curr->left != nullptr)
            graph[curr->val].push_back({curr->left->val, 'L'});
        
        if(curr->right != nullptr)
            graph[curr->val].push_back({curr->right->val, 'R'});
        
        buildGraph(graph, curr->left, curr);
        buildGraph(graph, curr->right, curr);
    }
    
    string bfs(vector<vector<PIC>>& graph, int n, int src, int dest){
        vector<bool> visited(n+1, false);

        queue<pair<int, string>> q;
        visited[src] = true;
        q.push({src, ""});

        while(!q.empty())
        {
            auto [curr, edges] = q.front();
            q.pop();
            
            if(curr == dest)
                return edges;

            for(auto [nei, dir]: graph[curr])
                if(!visited[nei])
                {
                    visited[nei] = true;
                    q.push({nei, edges + dir});
                }
        }

        return "";
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        int n = countNodes(root);

        vector<vector<PIC>> graph(n+1);
        buildGraph(graph, root, nullptr);

        return bfs(graph, n, startValue, destValue);
    }
};