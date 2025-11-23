class Solution {
private:
    typedef vector<int> VI;

public:
    // T.C.=O(n*log(k)), S.C.=O(k)
    // k: size of nums[], n: max size of nums[i][]
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // min-heap; {nums[i][j], i, j}
        priority_queue<VI, vector<VI>, greater<VI>> pq;

        int k = nums.size();
        int currMax = INT_MIN;
        int left = INT_MAX, right = INT_MIN;
        // for the 0th col push the elements of all the k arrays in heap
        // while keeping track of min and max vals in that col
        for(int i=0; i<k; i++)
        {
            pq.push({nums[i][0], i, 0});

            currMax = max(currMax, nums[i][0]);

            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
        }
        
        while(true)
        {
            int currMin = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            
            // a smaller range found
            if(currMax - currMin < right - left)
            {
                left = currMin;
                right = currMax;
            }

            // no more elements remaining in the ith array
            if(++j == nums[i].size())
                break;

            pq.push({nums[i][j], i, j});

            currMax = max(currMax, nums[i][j]);
        }

        return {left, right};
    }
};