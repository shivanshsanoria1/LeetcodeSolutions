class Solution {
public:
    typedef pair<float, pair<int, int>> PI; // {arr[i]/arr[j], {arr[i], arr[j]}}

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) { // T.C.=O((n^2)*log(n^2)), S.C.=O(k)
        vector<int> ans(2, 0);
        int n = arr.size();
        priority_queue<PI> pq; // max-heap
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)  
            {
                pq.push({(float)arr[i]/arr[j], {arr[i], arr[j]}});
                if(pq.size() > k) // if heap size exceeds k, pop the max element from heap
                    pq.pop();
            }
        ans[0] = pq.top().second.first;
        ans[1] = pq.top().second.second;
        return ans;
    }
};