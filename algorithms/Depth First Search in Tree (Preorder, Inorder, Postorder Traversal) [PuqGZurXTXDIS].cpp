#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val = -1;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    
    TreeNode(){
        this->val = -1;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    TreeNode(int val, TreeNode* left, TreeNode* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Tree{
private:
    vector<string> nums;

public:
    Tree(){
        this->nums.clear();
    }
    
    Tree(vector<string>& nums){
        this->nums = nums;
    }
    
    TreeNode* buildTree(){
        if(nums.empty() || nums[0] == "null")
            return nullptr;
        
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(nums[0]));
        int i = 0;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* currNode = q.front(); 
            q.pop();
            
            string leftVal = nums[++i];
            if(leftVal == "null")
                currNode->left = nullptr;
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(leftVal));
                currNode->left = leftNode;
                q.push(leftNode);
            }
            
            string rightVal = nums[++i];
            if(rightVal == "null")
                currNode->right = nullptr;
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(rightVal));
                currNode->right = rightNode;
                q.push(rightNode);
            }
        }
        
        return root;
    }
};

// --------------- START --------------- //

// curr - left - right
void preorder(TreeNode* curr){
    if(curr == nullptr)
        return;
    
    cout<<curr->val<<" ";
    preorder(curr->left);
    preorder(curr->right);
}

// left - curr - right
void inorder(TreeNode* curr){
    if(curr == nullptr)
        return;
    
    inorder(curr->left);
    cout<<curr->val<<" ";
    inorder(curr->right);
}

// left - right - curr
void postorder(TreeNode* curr){
    if(curr == nullptr)
        return;

    postorder(curr->left);
    postorder(curr->right);
    cout<<curr->val<<" ";
}

// --------------- END --------------- //

int main() {
    // node values of tree in level order serialization
    vector<string> nums = 
    { 
        "1", 
        "2", "3", 
        "4", "null", "5", "null", 
        "null", "null", "null", "6", 
        "null", "null"
    };
    
    Tree tr(nums);
    TreeNode* root = tr.buildTree();
    
    cout<<"Preorder: "<<endl;
    preorder(root);
    cout<<endl;
    
    cout<<"Inorder: "<<endl;
    inorder(root);
    cout<<endl;
    
    cout<<"Postorder: "<<endl;
    postorder(root);
    cout<<endl;
    
    cout<<"------------------"<<endl;
   
    return 0;
}

/*
         1
       /   \
      2     3
     / \   / \
    4   N  5  N
   /\      /\
  N  N    N  6
             /\
            N  N
*/