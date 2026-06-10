class Solution {
public:
    // T.C.=O(n*log(4)), S.C.=O(4*4)
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4)
            return 0;

        // max-heap; holds the smallest 4 elements
        priority_queue<int> maxhp;
        // min-heap; holds the largest 4 elements
        priority_queue<int, vector<int>, greater<int>> minhp;

        for(int num: nums)
        {
            maxhp.push(num);
            if(maxhp.size() > 4)
                maxhp.pop();
            
            minhp.push(num);
            if(minhp.size() > 4)
                minhp.pop();
        }

        // empty the max-heap to get the smallest 4 elements
        vector<int> mins;
        while(!maxhp.empty())
        {
            mins.push_back(maxhp.top());
            maxhp.pop();
        }
        reverse(mins.begin(), mins.end());

        // empty the min-heap to get the largest 4 elements
        vector<int> maxes;
        while(!minhp.empty())
        {
            maxes.push_back(minhp.top());
            minhp.pop();
        }

        int minDiff = INT_MAX;
        for(int i=0; i<4; i++)
            minDiff = min(minDiff, maxes[i] - mins[i]);

        return minDiff;
    }
};