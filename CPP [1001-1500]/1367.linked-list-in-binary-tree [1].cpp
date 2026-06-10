/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // returns true if the tree rooted at 'currTree' has a 
    // path that matches exactly with LL starting at 'currLL'
    bool dfs(TreeNode* currTree, ListNode* currLL){
        if(currLL == nullptr)
            return true;

        if(currTree == nullptr)
            return false;

        if(currTree->val != currLL->val)
            return false;

        return dfs(currTree->left, currLL->next) || dfs(currTree->right, currLL->next);
    }

    // traverse the tree in preorder fashion and run a dfs check for each node 
    // and return true if any check returns true
    bool preorder(TreeNode* currTree, ListNode* head){
        if(currTree == nullptr)
            return false;

        if(dfs(currTree, head))
            return true;

        return preorder(currTree->left, head) || preorder(currTree->right, head);
    }

public:
    // T.C.=O(t*l)
    // t: num of nodes in tree, l: num of nodes in LL
    bool isSubPath(ListNode* head, TreeNode* root) {
        return preorder(root, head);
    }
};