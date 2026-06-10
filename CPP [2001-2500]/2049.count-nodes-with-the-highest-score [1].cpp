class Solution {
private:
    typedef long long int lli;

    int dfs(vector<pair<int, int>>& tree, unordered_map<lli, int>& mp, int curr){
        if(curr == -1)
            return 0;
        
        int n=tree.size();

        auto [leftChild, rightChild] = tree[curr];

        // num of nodes in left-subtree
        int leftCount = dfs(tree, mp, leftChild);
        // num of nodes in right-subtree
        int rightCount = dfs(tree, mp, rightChild);
        // num of remaining nodes 
        int parentCount = n - 1 - leftCount - rightCount; 

        lli score = (lli)max(1, leftCount) * max(1, rightCount) * max(1, parentCount); 
        mp[score]++;

        return 1 + leftCount + rightCount;
    }

public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<pair<int, int>> tree(n, {-1, -1});
        // build the tree
        for(int i=1; i<n; i++)
        {
            if(tree[parents[i]].first == -1)
                tree[parents[i]].first = i;
            else
                tree[parents[i]].second = i;
        }

        // score -> freq
        unordered_map<lli, int> mp;

        dfs(tree, mp, 0);

        lli maxScore = 0;
        int maxScoreFreq = 0;

        for(auto [score, freq]: mp)
            if(score > maxScore)
            {
                maxScore = score;
                maxScoreFreq = freq;
            }

        return maxScoreFreq;
    }
};
/*
# tree[i].first, tree[i].second : left and right child of the ith node
# -1: NULL node
# while calculating the score, if any of (leftCount, rightCount, parentCount)
  is 0, replace them with 1
*/