class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(n*logn + m*logm), S.C.=O(n)
    // n: size of difficulty[] and profit[], m: size of worker[]
    // min-heap
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Step 1: create a min-heap of pairs of {difficulty[i], profit[i]}
        priority_queue<PII, vector<PII>, greater<PII>> pq;

        for(int i=0; i<difficulty.size(); i++)
            pq.push({difficulty[i], profit[i]});
        
        // Step 2: sort the worker[]
        sort(worker.begin(), worker.end());

        // Step 3: for each worker find the max-difficulty in heap <=
        // max-difficulty of that worker and 
        // add the max-profit upto that index to the total-profit 
        
        int maxProfit = 0;
        int totalProfit = 0;

        for(int maxDiff: worker)
        {
            while(!pq.empty() && pq.top().first <= maxDiff)
            {
                maxProfit = max(maxProfit, pq.top().second);
                pq.pop();
            }

            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};