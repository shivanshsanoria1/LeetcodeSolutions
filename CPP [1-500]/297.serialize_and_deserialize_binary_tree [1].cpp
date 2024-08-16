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
    string preorderSerialize(TreeNode* curr){
        if(curr == nullptr)
            return "N,";

        return to_string(curr->val) + "," + preorderSerialize(curr->left) + preorderSerialize(curr->right); 
    }

    TreeNode* buildTree(queue<string>& q){
        if(q.empty())
            return nullptr;

        string curr = q.front();
        q.pop();

        if(curr == "N")
            return nullptr;

        TreeNode* currNode = new TreeNode(stoi(curr));

        currNode->left = buildTree(q);
        currNode->right = buildTree(q);

        return currNode;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return preorderSerialize(root);
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