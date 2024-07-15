/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // BFS
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            Node* prev = nullptr;

            while(size--)
            {
                Node* curr = q.front();
                q.pop();
                
                if(prev != nullptr)
                    prev->next = curr;
                prev = curr;

                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }
        }

        return root;
    }
};
// same as [116. populating-next-right-pointers-in-each-node]