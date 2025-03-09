class Solution {
public:
    // T.C.=O(n*(n*log(k) + k*log(k))), S.C.=O(k)
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long int> ans(n, 0);

        for(int i=0; i<n; i++)
        {
            // min-heap
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int j=0; j<n; j++)
            {
                if(i == j || nums1[i] <= nums1[j])
                    continue;
                    
                pq.push(nums2[j]);
                if(pq.size() == k+1)
                    pq.pop();
            }

            while(!pq.empty())
            {
                ans[i] += pq.top();
                pq.pop();
            }
        }

        return ans;
    }
};