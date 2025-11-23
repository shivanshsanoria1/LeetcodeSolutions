class Solution {
public:
    // T.C.=O(n*logn + m*logn), S.C.=O(n)
    // n: size of difficulty[] and profit[], m: size of worker[]
    // Sorting + Binary-Search
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();

        // Step 1: create a vector of pairs of difficulty and profit
        vector<pair<int, int>> nums(n);
        for(int i=0; i<n; i++)
            nums[i] = {difficulty[i], profit[i]};

        // Step 2: sort by difficulty
        sort(nums.begin(), nums.end());
        
        // Step 3: calulate the prefix-max-profit, ie, 
        // replace each profit value with the max-profit found upto that index
        for(int i=1; i<n; i++)
            nums[i].second = max(nums[i].second, nums[i-1].second);
        

        // Step 4: for each worker find the max-difficulty in the sorted vector <=
        // max-difficulty of that worker and 
        // add the max-profit upto that index to the total-profit
        
        int totalProfit = 0;

        for(int maxDiff: worker)
        {
            int left = 0, right = n-1;
            int idx = -1;

            while(left <= right)
            {
                int mid = left + (right - left)/2;

                if(nums[mid].first <= maxDiff)
                {
                    idx = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }

            if(idx != -1)
                totalProfit += nums[idx].second;
        }

        return totalProfit;
    }
};