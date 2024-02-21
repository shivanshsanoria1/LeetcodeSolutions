class Solution {
public:
    typedef pair<float, pair<int, int>> PI; // {arr[i]/arr[j], {arr[i], arr[j]}}

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) { // T.C.=O((n^2)*log(n^2)), S.C.=O(n^2)
        vector<int> ans(2, 0);
        int n = arr.size();
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)  
                pq.push({(float)arr[i]/arr[j], {arr[i], arr[j]}});
        while(k--)
        {
            auto curr = pq.top();
            pq.pop();
            ans[0] = curr.second.first;
            ans[1] = curr.second.second;
        }
        return ans;
    }
};