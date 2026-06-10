class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Monotonic-decreasing-deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { 
        vector<int> ans;
        // maintain deque in decreasing order, 
        // stores indexes and not values
        deque<int> dq; 

        for(int i=0; i<nums.size(); i++)
        {
            // pop the elements from the back of dequeue which are < curr element 
            while(!dq.empty() && nums[dq.back()] < nums[i]) 
                dq.pop_back();

            // pop the invalid indices from the front of dequeue
            while(!dq.empty() && dq.front() < i-k+1) 
                dq.pop_front();

            // push the curr index at the back of queue
            dq.push_back(i); 
            
            // min valid index is 0
            if(i-k+1 >= 0) 
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
/*
# the index range for each window is [i-k+1, i]
# for a deque left-side is the front and right-side is the back
# deque: (front) |_|_|_|_|_|_|_| (back)
*/