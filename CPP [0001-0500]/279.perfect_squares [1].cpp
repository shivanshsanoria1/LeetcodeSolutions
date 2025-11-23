class Solution {
private:
    // BFS + visited array
    int coinChange(vector<int>& coins, int amount) { 
        // 0 coins are required to make 0 amount
        if(amount == 0) 
            return 0;
        // keeps track of visited status of all the amounts from 0 to 'amount'
        vector<bool> visited(amount + 1, false); 
        queue<int> q;
        q.push(amount);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            while(size--)
            {
                int currAmount = q.front();
                q.pop();
                for(int i=0; i<coins.size(); i++)
                {
                    int nextAmount = currAmount - coins[i];
                    // skip the -ive amounts
                    if(nextAmount < 0) 
                        continue;
                    // skip the already visited amounts
                    if(visited[nextAmount]) 
                        continue;
                    // mark the amount to be pushed in queue as visited
                    visited[nextAmount] = true;
                    // found the min level, ie, the ans
                    if(nextAmount == 0) 
                        return level;
                    q.push(nextAmount);
                }
            }
        }
        // amount cannot be formed from the given coins
        return -1; 
    }

public: 
    int numSquares(int n) {
        vector<int> perfect;
        for(int x=1; x*x<=n; x++)
            perfect.push_back(x*x);
        return coinChange(perfect, n);
    }
};

// used the solution of Leetcode-322 Coin Change