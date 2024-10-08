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
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { 
        string serial = "";
        if(root == nullptr)
            return serial;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == nullptr)
            {
                serial += "N,";
                continue;
            }

            serial += to_string(curr->val) + ",";

            q.push(curr->left);
            q.push(curr->right);
        }

        // remove the last ','
        serial.pop_back();
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) 
            return nullptr; 

        stringstream ss(data);
        string val = ""; 

        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root); 
        
        while(!q.empty()) 
        {
            TreeNode* currNode = q.front(); 
            q.pop(); 
            
            getline(ss, val, ',');
            if(val == "N") 
                currNode->left = nullptr; 
            else 
            {
                TreeNode* leftNode = new TreeNode(stoi(val)); 
                currNode->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(ss, val, ',');
            if(val == "N") 
                currNode->right = nullptr; 
            else 
            {
                TreeNode* rightNode = new TreeNode(stoi(val)); 
                currNode->right = rightNode;
                q.push(rightNode); 
            }
        }
        
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));