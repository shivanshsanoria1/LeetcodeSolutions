class Solution {
public:
    // T.C.=O(n + m + w), S.C.=O(w)
    // n: size of difficulty[] and profit[], m: size of worker[]
    // w: max-val in worker[]
    // Counting-sort + prefix-maximum
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Step 1: find the max-difficulty that any worker can handle
        int maxWorkerDifficulty = *max_element(worker.begin(), worker.end());

        // Step 2: create a vector of size (1 + maxWorkerDifficulty)
        vector<int> maxProfits(1 + maxWorkerDifficulty, 0);

        // Step 3: update the max-profit for each difficulty <= 
        // max-difficulty that any worker can handle
        for(int i=0; i<difficulty.size(); i++)
            if(difficulty[i] <= maxWorkerDifficulty)
                maxProfits[difficulty[i]] = max(maxProfits[difficulty[i]], profit[i]);
        
        // Step 4: calculate the prefix-max-profit, ie, 
        // max-profit for completing the job with difficulty <= i
        for(int i=1; i<maxProfits.size(); i++)
            maxProfits[i] = max(maxProfits[i], maxProfits[i-1]);
        
        // Step 5: find the max-profit each worker can get 
        // with their respective max difficulty handling capacity
        int totalProfit = 0;
        for(int maxDiff: worker)
            totalProfit += maxProfits[maxDiff];

        return totalProfit;
    }
};