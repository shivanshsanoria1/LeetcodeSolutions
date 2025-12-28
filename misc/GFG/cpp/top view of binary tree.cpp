class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root) //BFS
    {
        //Your code here
        vector<int> ans;
        if(root==NULL)
            return ans;
        map<int,int> mp; //x coordinate -> topmost node value with that coordinate
        queue<pair<Node*,int>> q;
        q.push({root,0}); //root has x coordinate 0
        while(!q.empty())
        {
            auto it= q.front();
            q.pop();
            Node* curr= it.first;
            int x= it.second; //x coordinate of curr node
            if(mp.find(x)==mp.end()) //x not found in map
                mp[x]=curr->data;
            if(curr->left!=NULL)
                q.push({curr->left,x-1});
            if(curr->right!=NULL)
                q.push({curr->right,x+1});
        }
        for(auto it: mp)
            ans.push_back(it.second);
        return ans;
    }
};