class Solution {
public:
    // T.C.=O(n + k), S.C.=O(k)
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flips = 0;
        // stores indexes and not values
        queue<int> q;

        for(int i=0; i<n; i++)
        {
            // pop the indexes which are out of 
            // the window of size k and ending at index i
            while(!q.empty() && i - q.front() + 1 > k)
                q.pop();
            
            // even flips: num is unchanged
            // odd flips: num is flipped
            int curr = q.size() % 2 == 0 ? nums[i] : !nums[i];

            if(curr == 0)
            {
                // window of size k starting at 
                // index i cannot be formed
                if(i > n-k)
                    return -1;

                q.push(i);
                flips++;
            }
        }

        return flips;
    }
};