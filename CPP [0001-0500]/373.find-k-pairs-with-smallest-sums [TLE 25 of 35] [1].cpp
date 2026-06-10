class Solution {
public:
    typedef pair<int, pair<int, int>> PI;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        int n1 = nums1.size(), n2 = nums2.size();
        // push all the pairs (formed from nums1 and nums2) and their respective sums in the min-heap
        for(int i=0; i<n1; i++)
            for(int j=0; j<n2; j++)
                pq.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
        // pop out min(k, min-heap size) pairs from min-heap
        while(!pq.empty() && k--)
        {
            auto curr = pq.top();
            pq.pop();
            ans.push_back({curr.second.first, curr.second.second});
        }
        return ans;
    }
};