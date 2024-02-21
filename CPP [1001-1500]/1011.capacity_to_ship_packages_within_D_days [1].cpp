class Solution {
public:
    bool canPartition(vector<int>& weights, int wtLimit, int days){ 
        int currWt = 0; // curr weight
        int currDays = 1; // atleast 1 day is needed
        for(int wt: weights)
        {
            if(currWt + wt > wtLimit) // curr weight exceeds the weight limit
            {
                currWt = 0; // reset the curr weight
                currDays++; // another day is needed
            }
            if(currDays > days)
                return false;
            currWt += wt;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) { // T.C.=O(n*log(500*n)), S.C.=O(1)
        int totalWt = 0; // max capccity of the ship
        int maxWt = 0; // min capccity of the ship
        for(int wt: weights)
        {
            totalWt += wt;
            maxWt = max(maxWt, wt);
        }

        int left = maxWt, right = totalWt;
        int ans = totalWt;
        while(left <= right)
        {
            int mid = left + (right-left)/2; // curr capcity of the ship
            if(canPartition(weights, mid, days))
            {
                ans = min(ans, mid);
                right = mid - 1; // reduce the capacity
            }
            else 
                left = mid + 1; // increase the capacity
        }
        return ans;
    }
};