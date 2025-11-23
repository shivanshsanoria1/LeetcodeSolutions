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
        if(root == NULL)
            return serial;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL)
            {
                serial += "N,";
                continue;
            }
            serial += to_string(curr->val) + ",";
            q.push(curr->left);
            q.push(curr->right);
        }
        serial.pop_back();
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) 
            return NULL; 

        stringstream ss(data);
        string val = ""; 

        getline(ss, val, ',');
        TreeNode *root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root); 
        
        while(!q.empty()) 
        {
            TreeNode *currNode = q.front(); 
            q.pop(); 
            
            getline(ss, val, ',');
            if(val == "N") 
                currNode->left = NULL; 
            else 
            {
                TreeNode* leftNode = new TreeNode(stoi(val)); 
                currNode->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(ss, val, ',');
            if(val == "N") 
                currNode->right = NULL; 
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
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

// same as Leetcode-297 'Serialize and Deserialize Binary Tree'