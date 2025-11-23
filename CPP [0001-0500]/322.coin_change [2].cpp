class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { //BFS + visited array
        if(amount == 0) //0 coins are required to make 0 amount
            return 0;
        int n=coins.size(), level=0;
        vector<bool> visited(amount+1,false); //keeps track of visited status of all the amounts from 0 to 'amount'
        queue<int> q;
        q.push(amount);
        while(!q.empty())
        {
            int size= q.size();
            level++;
            while(size--)
            {
                int curr_amount= q.front();
                q.pop();
                for(int i=0; i<n; i++)
                {
                    int next_amount= curr_amount-coins[i];
                    if(next_amount < 0) //skip the -ive amounts
                        continue;
                    if(visited[next_amount] == true) //skip the already visited amounts
                        continue;
                    visited[next_amount]=true; //mark the amount to be pushed in queue as visited
                    if(next_amount == 0) //found the min level, ie, the ans
                        return level;
                    q.push(next_amount);
                }
            }
        }
        return -1; //amount cannot be formed from the given coins
    }
};