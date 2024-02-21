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
public:
    void inorderTraversal(TreeNode* curr, vector<int> &inorder)
    {
        if(curr == NULL)
            return;
        inorderTraversal(curr->left, inorder);
        inorder.push_back(curr->val);
        inorderTraversal(curr->right, inorder);
    }

    vector<int> sortedArrayFrom2SortedArrays(vector<int> vec1, vector<int> vec2)
    {
        int n1 = vec1.size(), n2 = vec2.size();
        int i=0, j=0;
        vector<int> vec;
        while(i < n1 && j < n2)
        {
            if(vec1[i] <= vec2[j])
            {
                vec.push_back(vec1[i]);
                i++;
            }
            else
            {
                vec.push_back(vec2[j]);
                j++;
            }
        }
        while(i < n1) // elements are left in vec1
        {
            vec.push_back(vec1[i]);
            i++;
        }
        while(j < n2) // elements are left in vec2
        {
            vec.push_back(vec2[j]);
            j++;
        }
        return vec;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) { // T.C.=O(m+n), S.C.=O(m+n)
        vector<int> inorder1, inorder2;
        inorderTraversal(root1, inorder1);
        inorderTraversal(root2, inorder2);
        return sortedArrayFrom2SortedArrays(inorder1, inorder2);
    }
};