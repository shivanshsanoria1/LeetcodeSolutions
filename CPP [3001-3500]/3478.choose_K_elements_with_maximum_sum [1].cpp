class Solution {
public:
    // T.C.=O(n*log(n) + n*log(k)), S.C.=O(n + k)
    // sorting, 2-pointer, min-heap
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        // {nums1[i], i}
        vector<pair<int, int>> temp1;
        for(int i=0; i<n; i++)
            temp1.push_back({nums1[i], i});

        sort(temp1.begin(), temp1.end());

        // min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        // sum of elements in min-heap
        long long int pq_sum = 0;
        vector<long long int> ans(n, 0);

        for(int i=0, j=0; i<n; i++)
        {
            int currIdx = temp1[i].second;

            while(j < i && temp1[j].first < temp1[i].first)
            {
                int prevIdx = temp1[j].second;
                
                pq_sum += nums2[prevIdx];
                pq.push(nums2[prevIdx]);

                if(pq.size() == k+1)
                {
                    pq_sum -= pq.top();
                    pq.pop();
                }

                j++;
            }

            ans[currIdx] = pq_sum;
        }

        return ans;
    }
};