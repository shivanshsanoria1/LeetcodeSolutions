class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { //T.C.=O(n) , S.C.=O(n)
        vector<int> ans;
        deque<int> q; //maintain the deque in decreasing order, stores index and not value
        for(int i=0; i<nums.size(); i++)
        {
            while(!q.empty() && nums[q.back()] < nums[i]) //pop the elements which are < curr element from the back
                q.pop_back();
            while(!q.empty() && q.front() < i-k+1) //pop the invalid indices from the front
                q.pop_front();
            q.push_back(i); //push the curr index at the back of queue
            if(i-k+1 >= 0) //min valid index is 0
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
//the index range for each window is [n-k+1,i]