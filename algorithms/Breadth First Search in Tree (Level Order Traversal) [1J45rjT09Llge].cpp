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

void levelorder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        cout<<curr->val<<" ";
        
        if(curr->left != nullptr)
            q.push(curr->left);
        if(curr->right != nullptr)
            q.push(curr->right);
    }
}

void levelorder_levelwise(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    
    while(!q.empty())
    {
        int sz = q.size();
        cout<<"Level "<<level<<": ";
        level++;
        
        while(sz--)
        {
            TreeNode* curr = q.front();
            q.pop();
            cout<<curr->val<<" ";
            
            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
        }
        
        cout<<endl;
    }
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
    
    cout<<"Levelorder: "<<endl;
    levelorder(root);
    cout<<endl<<endl;
    
    cout<<"Levelorder levelwise: "<<endl;
    levelorder_levelwise(root);
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