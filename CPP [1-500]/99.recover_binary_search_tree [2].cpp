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
    int index;
    
    void inorder1(vector<int>& vec, TreeNode* curr) //do inorder traversal and copy node values in vector
    {
        if(curr==NULL)
            return;
        inorder1(vec,curr->left);
        vec.push_back(curr->val);
        inorder1(vec,curr->right);
    }
    
    void inorder2(vector<int>& vec, TreeNode* curr) //do inorder traversal and copy sorted vector values in node
    {
        if(curr==NULL)
            return;
        inorder2(vec,curr->left);
        curr->val=vec[index];
        index++;
        inorder2(vec,curr->right);
    }
    
    void sort(vector<int>& vec)
    {
        int n=vec.size();
        int x=-1, y=-1; //indexes of elements to be swapped
        for(int i=1; i<n; i++)
            if(vec[i-1] > vec[i])
            {
                if(x==-1)
                    x=i-1;
                y=i;
            }
        swap(vec[x],vec[y]);
    }
    
    void recoverTree(TreeNode* root) { //T.C.=O(n) , S.C.=O(n)
        vector<int> vec;
        inorder1(vec,root);
        sort(vec);
        index=0;
        inorder2(vec,root);
    }
};
//inorder traversal of BST gives values in sorted form