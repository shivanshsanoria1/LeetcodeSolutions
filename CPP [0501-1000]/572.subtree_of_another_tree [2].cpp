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
    void inorder(TreeNode* root, vector<int>& vec)
    {
        if(root==NULL)
        {
            vec.push_back(INT_MIN); //for NULL nodes push INT_MIN in the array
            return;
        }
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    
    void preorder(TreeNode* root, vector<int>& vec)
    {
        if(root==NULL)
        {
            vec.push_back(INT_MIN); //for NULL nodes push INT_MIN in the array
            return;
        }
        vec.push_back(root->val);
        preorder(root->left,vec);
        preorder(root->right,vec);
    }
    
    bool isSubarray(vector<int>& vec1, vector<int>& vec2) //returns true if vec2 is a subarray of vec1
    {
        int n1= vec1.size(), n2=vec2.size();
        if(n1 < n2) //array2 should not be longer than array1
            return false;
        for(int start=0; start <= n1-n2; start++)
        {
            int i=start, j=0;
            while(j < n2)
            {
                if(vec1[i] != vec2[j])
                    break;
                i++;
                j++;
            }
            if(j==n2)
                return true;
        }
        return false;
    }
    
    bool isSubtree(TreeNode* root1, TreeNode* root2) {
        vector<int> inorder1, inorder2;
        vector<int> preorder1, preorder2;
        
        inorder(root1,inorder1);
        inorder(root2,inorder2);
        if(isSubarray(inorder1,inorder2)==false)
            return false;
        
        preorder(root1,preorder1);
        preorder(root2,preorder2);
        if(isSubarray(preorder1,preorder2)==false)
            return false;
        
        return true;
    }
};