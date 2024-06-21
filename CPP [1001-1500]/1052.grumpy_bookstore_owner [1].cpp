class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window (fixed-length)
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();

        // satisfied customer count (without owner's secret technique)
        int initialSatisfiedCount = 0;
        for(int i=0; i<n; i++)
            if(grumpy[i] == 0)
                initialSatisfiedCount += customers[i];

        int maxSatisfiedCount = 0;
        int currSatisfiedCount = 0;
        
        // satisfied customer count for window in range [0, minutes)
        for(int i=0; i < minutes; i++)
            if(grumpy[i] == 1)
            {
                currSatisfiedCount += customers[i];
                maxSatisfiedCount = currSatisfiedCount;
            }

        // keep on shifting the window by adding 1 customer to the right
        // and removing 1 customer from the left
        int left = 1, right = minutes;
        while(right < n)
        {
            // newly added customer (initially unsatisfied) is now satisfied
            if(grumpy[right] == 1)
                currSatisfiedCount += customers[right];
            // recently removed customer (previously satisfed) is now unsatisfied
            if(grumpy[left - 1] == 1)
                currSatisfiedCount -= customers[left - 1];
            
            maxSatisfiedCount = max(maxSatisfiedCount, currSatisfiedCount);

            left++;
            right++;
        }

        return initialSatisfiedCount + maxSatisfiedCount;
    }
};
// all the customers in the window are satisfied