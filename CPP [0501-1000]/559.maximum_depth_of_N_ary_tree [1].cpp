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
    int dfs(Node* curr, int level){
        int maxLevel = 0;

        for(Node* child: curr->children)
            maxLevel = max(maxLevel, dfs(child, level + 1));
        
        return 1 + maxLevel;
    }

public:
    int maxDepth(Node* root) {
        return root == nullptr ? 0 : dfs(root, 1); 
    }
};