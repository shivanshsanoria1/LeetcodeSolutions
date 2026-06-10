/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* dfs(unordered_map<Node*, Node*>& mp, Node* curr){
        if(mp.find(curr) != mp.end())
            return mp[curr];
        
        Node* deepCurr = new Node(curr->val);
        mp[curr] = deepCurr;

        for(Node* nei: curr->neighbors)
            deepCurr->neighbors.push_back(dfs(mp, nei));

        return deepCurr;
    }

public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        
        // node -> deep copy of node
        unordered_map<Node*, Node*> mp;

        return dfs(mp, node);
    }
};