class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        // push the indexes in queue
        queue<int> q;
        for(int i=0; i<n; i++)
            q.push(i);

        sort(deck.begin(), deck.end());

        vector<int> ans(n, 0);
        int j = 0;
        bool take = true;

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            if(take)
            {
                ans[i] = deck[j];
                j++;
            }
            else
                q.push(i);

            take = !take;
        }
        
        return ans;
    }
};