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
    typedef pair<TreeNode*, TreeNode*> PTT;

    PTT searchKey(TreeNode* curr, TreeNode* parent, int key){
        if(curr == nullptr)
            return {curr, parent};
        
        if(curr->val > key)
            return searchKey(curr->left, curr, key);
        else if(curr->val < key)
            return searchKey(curr->right, curr, key);

        // at this point: curr->val == key
        return {curr, parent};
    }

    PTT findMaxNodeInLeftSubtree(TreeNode* curr, TreeNode* parent){
        if(curr->right == nullptr)
            return {curr, parent};
        
        return findMaxNodeInLeftSubtree(curr->right, curr);
    }    

    PTT findMinNodeInRightSubtree(TreeNode* curr, TreeNode* parent){
        if(curr->left == nullptr)
            return {curr, parent};
        
        return findMinNodeInRightSubtree(curr->left, curr);
    }   

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // find the node with value 'key' and its parent node
        auto [keyNode, keyNodeParent] = searchKey(root, nullptr, key);
        
        // key-node not found
        if(keyNode == nullptr)
            return root;

        // key-node has a left-child
        if(keyNode->left != nullptr)
        {
            // for the tree rooted at key-node:
            // find the node with max value in left-subtree and its parent node
            auto [maxLeftNode, maxLeftNodeParent] = findMaxNodeInLeftSubtree(keyNode->left, keyNode);

            keyNode->val = maxLeftNode->val;

            // check if maxLeftNode is the left or right child
            if(maxLeftNodeParent->left == maxLeftNode)
                maxLeftNodeParent->left = maxLeftNode->left;
            else
                maxLeftNodeParent->right = maxLeftNode->left;

            delete maxLeftNode;

            return root;
        }
        // key-node has a right-child
        else if(keyNode->right != nullptr)
        {
            // for the tree rooted at key-node:
            // find the node with min value in right-subtree and its parent node
            auto [minRightNode, minRightNodeParent] = findMinNodeInRightSubtree(keyNode->right, keyNode);

            keyNode->val = minRightNode->val;

            // check if minRightNode is the left or right child
            if(minRightNodeParent->left == minRightNode)
                minRightNodeParent->left = minRightNode->right;
            else
                minRightNodeParent->right = minRightNode->right;

            delete minRightNode;

            return root;
        }
        
        // at this point key-node does not have any child

        // key-node does not have a parent node, ie, 
        // key-node is the root node of the given binary tree
        if(keyNodeParent == nullptr)
        {
            delete keyNode;
            return nullptr;
        }

        // check if key-node is the left or right child
        if(keyNodeParent->left == keyNode)
            keyNodeParent->left = nullptr;
        else
            keyNodeParent->right = nullptr;

        delete keyNode;

        return root;
    }
};