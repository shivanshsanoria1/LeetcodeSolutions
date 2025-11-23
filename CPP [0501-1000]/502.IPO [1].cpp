class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(n*logn), S.C.=O(n)
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // max-heap; {profit, capital}
        priority_queue<PII> maxHeap;
        // min-heap; {capital, profit}
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;

        int n=profits.size();

        for(int i=0; i<n; i++)
            minHeap.push({capital[i], profits[i]});
        
        while(k--)
        {
            // pop out all the pairs with capital <= w from min-heap
            // and push them into the max-heap
            while(!minHeap.empty() && minHeap.top().first <= w)
            {
                auto [cap, prof] = minHeap.top();
                minHeap.pop();
                maxHeap.push({prof, cap});
            }

            // profit cannot be increased with the curr available capital 'w'
            if(maxHeap.empty())
                break;

            w += maxHeap.top().first;
            maxHeap.pop();
        }

        return w;
    }
};