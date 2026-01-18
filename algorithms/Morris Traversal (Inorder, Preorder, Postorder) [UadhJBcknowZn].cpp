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

// left - curr - right
void morrisInorder(TreeNode* root){
    TreeNode* curr = root;
    
    while(curr != nullptr)
    {
        if(curr->left == nullptr)
        {
            cout<<curr->val<<" ";
            curr = curr->right;
            continue;
        }
        
        TreeNode* predecessor = curr->left;
        while(predecessor->right != nullptr && predecessor->right != curr)
            predecessor = predecessor->right;
        
        if(predecessor->right == nullptr)
        {
            predecessor->right = curr;
            curr = curr->left;
        }
        else
        {
            predecessor->right = nullptr;
            cout<<curr->val<<" ";
            curr = curr->right;
        }
    }
}

// curr - left - right
void morrisPreorder(TreeNode* root){
    TreeNode* curr = root;
    
    while(curr != nullptr)
    {
        if(curr->left == nullptr)
        {
            cout<<curr->val<<" ";
            curr = curr->right;
            continue;
        }
        
        TreeNode* predecessor = curr->left;
        while(predecessor->right != nullptr && predecessor->right != curr)
            predecessor = predecessor->right;
        
        if(predecessor->right == nullptr)
        {
            predecessor->right = curr;
            cout<<curr->val<<" ";
            curr = curr->left;
        }
        else
        {
            predecessor->right = nullptr;
            curr = curr->right;
        }
    }
}

// left - right - curr
void morrisPostorder(TreeNode* root){
    vector<int> nums;
    TreeNode* curr = root;
    
    while(curr != nullptr)
    {
        if(curr->right == nullptr)
        {
            nums.push_back(curr->val);
            curr = curr->left;
            continue;
        }
        
        TreeNode* predecessor = curr->right;
        while(predecessor->left != nullptr && predecessor->left != curr)
            predecessor = predecessor->left;
        
        if(predecessor->left == nullptr)
        {
            predecessor->left = curr;
            nums.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            predecessor->left = nullptr;
            curr = curr->left;
        }
    }
    
    reverse(nums.begin(), nums.end());
    for(int num: nums)
        cout<<num<<" ";
    cout<<endl;
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
    
    cout<<"Morris-Inorder: "<<endl;
    morrisInorder(root);
    cout<<endl;
    
    cout<<"Morris-Preorder: "<<endl;
    morrisPreorder(root);
    cout<<endl;
    
    cout<<"Morris-Postorder: "<<endl;
    morrisPostorder(root);
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