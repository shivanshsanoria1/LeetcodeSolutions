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
    
    void dfs(vector<vector<PIC>>& graph, vector<bool>& visited, string& edges, string& ans, int curr, int dest){
        if(visited[curr])
            return;

        visited[curr] = true;

        if(curr == dest)
        {
            ans = edges;
            return;
        }

        for(auto [nei, dir]: graph[curr])
        {
            edges += dir;
            dfs(graph, visited, edges, ans, nei, dest);
            edges.pop_back();
        }
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        int n = countNodes(root);

        vector<vector<PIC>> graph(n+1);
        buildGraph(graph, root, nullptr);

        vector<bool> visited(n+1, false);
        string edges = "";
        string ans = "";
        dfs(graph, visited, edges, ans, startValue, destValue);

        return ans;
    }
};