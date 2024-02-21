class Solution {
public:
    void dfs(vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited, int curr){
        if(curr == -1) // curr node does not exist
            return;
        if(visited[curr]) // curr node is already visited
            return;
        visited[curr] = true; // mark the curr node as visited
        // left-subtree
        dfs(leftChild, rightChild, visited, leftChild[curr]);
        // right-subtree
        dfs(leftChild, rightChild, visited, rightChild[curr]);
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) { // T.C.=O(n), S.C.=O(n)
        // stores the num of parents of the ith node
        vector<int> parentCount(n, 0);
        for(int i=0; i<n; i++)
        {
            if(leftChild[i] != -1) // left child exists
                parentCount[leftChild[i]]++;
            if(rightChild[i] != -1) // right child exists
                parentCount[rightChild[i]]++;
        }

        int rootCount = 0;
        int root = -1;
        for(int i=0; i<n; i++)
        {
            // more than 1 parent found for a node
            if(parentCount[i] > 1)
                return false;
            // node with no parent, ie, root node
            if(parentCount[i] == 0)
            {
                rootCount++;
                root = i;
            }
            // more than 1 root node found
            if(rootCount > 1)
                return false;
        }

        vector<bool> visited(n, false);
        dfs(leftChild, rightChild, visited, root);
        // check if all nodes are reachable from root node
        for(int i=0; i<n; i++)
            if(!visited[i]) // unreachable node from root node
                return false;
        return true;
    }
};