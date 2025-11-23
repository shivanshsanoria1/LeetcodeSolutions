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
class CBTInserter {
private:
    TreeNode* root = nullptr;
    queue<TreeNode*> q;

    void insertCBTinQueue(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            // only the nodes with 1 or 2 empty childs 
            // allow the insertion of new nodes
            if(curr->left == nullptr || curr->right == nullptr)
                this->q.push(curr);

            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
        }
    }

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        
        insertCBTinQueue(root);
    }
    
    int insert(int val) {
        int parentVal = q.front()->val;

        TreeNode* newNode = new TreeNode(val);

        // left-child is empty
        if(q.front()->left == nullptr)
            q.front()->left = newNode;
        // right-child is empty
        else // q.front()->right == nullptr
        {
            q.front()->right = newNode;
            // node at queue-front has no empty child remaining
            q.pop();
        }
        
        q.push(newNode);

        return parentVal;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */