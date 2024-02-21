/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string preorder(TreeNode* curr){
        if(curr == NULL)
            return "N,";
        return to_string(curr->val) + "," + preorder(curr->left) + preorder(curr->right); 
    }

    TreeNode* buildTree(queue<string>& q){
        if(q.empty())
            return NULL;

        string curr = q.front();
        q.pop();

        if(curr == "N")
            return NULL;

        TreeNode* currNode = new TreeNode(stoi(curr));
        currNode->left = buildTree(q);
        currNode->right = buildTree(q);
        return currNode;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return preorder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string val = "";
        for(char ch: data)
        {
            if(ch == ',')
            {
                q.push(val);
                val = "";
            }
            else
                val += ch;
        }
        q.push(val);
        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));