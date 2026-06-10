class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        // cannot break only 1 stone
        if(n == 1) 
            return stones[0];

        int max1_idx = -1, max2_idx = -1;

        // atmost (n-1) steps are required for n stones
        for(int k=0; k<n-1; k++) 
        {
            int max1 = -1, max2 = -1;

            // find max1 and max2 in each step
            for(int i=0; i<n; i++) 
            {
                // new max1 found
                if(stones[i] >= max1) 
                {
                    max2_idx = max1_idx; 
                    max1_idx = i; 
                    max2 = max1; 
                    max1 = stones[i];
                }
                // new max2 found
                else if(stones[i] > max2) 
                {
                    max2_idx = i; 
                    max2 = stones[i]; 
                }
            }

            // all stones are borken
            if(max1 == -1 && max2 == -1)
                break;

            // replace max1 with (max1 - max2) in the array
            stones[max1_idx] = max1 - max2; 
            // replace max2 with 0 in the array
            stones[max2_idx] = 0; 
        }

        return stones[max1_idx];
    }
};
/*
# at each step either 2 or 1 stones are destroyed
# in the worst case, 1 stone is destroyed at each step
  so, (n-1) steps are required to reach 1 stone
*/