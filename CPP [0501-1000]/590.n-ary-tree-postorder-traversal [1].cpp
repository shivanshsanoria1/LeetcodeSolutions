/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void dfs(vector<int>& ans, Node* curr){
        for(Node* child: curr->children)
            dfs(ans, child);
            
        ans.push_back(curr->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> ans;

        if(root == nullptr)
            return ans;

        dfs(ans, root);

        return ans;
    }
};