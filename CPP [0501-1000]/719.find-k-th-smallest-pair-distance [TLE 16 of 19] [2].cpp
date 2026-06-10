class Solution {
public:
    // T.C.=O((n^2)*log(k)), S.C.=O(k)
    int smallestDistancePair(vector<int>& nums, int k) { 
        int n=nums.size();
        // max-heap
        priority_queue<int> pq;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                pq.push(abs(nums[i] - nums[j]));
                if(pq.size() == k+1)
                    pq.pop();
            }

        return pq.top();
    }
};