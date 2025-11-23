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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        if(root == nullptr)
            return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> levelVals;

            while(size--)
            {
                Node* curr = q.front();
                q.pop();
                levelVals.push_back(curr->val);

                for(Node* child: curr->children)
                    q.push(child);
            }

            ans.push_back(levelVals);
        }

        return ans;
    }
};