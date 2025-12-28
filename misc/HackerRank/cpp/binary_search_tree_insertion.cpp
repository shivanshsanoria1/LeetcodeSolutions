/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int key) {
        Node *newnode = new Node(key);
        if(root==NULL)
            return newnode;
        Node *curr=root;
        while(1)
        {
            if(key < curr->data)
            {
                if(curr->left==NULL)
                {
                    curr->left=newnode;
                    break;
                }
                curr=curr->left;
            }
            else if(key > curr->data)
            {
                if(curr->right==NULL)
                {
                    curr->right=newnode;
                    break;
                }
                curr=curr->right;
            }
        }
        return root;
    }