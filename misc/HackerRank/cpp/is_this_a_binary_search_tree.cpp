/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool checkBST(Node* root) {
		return solve(root,-1,10001); // 0<=data<=10000 (given)
	}

    bool solve(Node *root, int min, int max)
    {
        if(root==NULL)
            return true;
        if(!(root->data > min && root->data < max))
            return false;
        return (solve(root->left,min,root->data) && solve(root->right,root->data,max));
    }