class Solution {
private:
    // {arr[i]/arr[j], {arr[i], arr[j]}}
    typedef pair<float, pair<int, int>> PFII;

public: 
    // T.C.=O((n^2)*logk), S.C.=O(k)
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) { 
        int n=arr.size();
        // max-heap
        priority_queue<PFII> pq; 

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)  
            {
                pq.push({(float)arr[i]/arr[j], {arr[i], arr[j]}});
                
                if(pq.size() == k+1) 
                    pq.pop();
            }

        vector<int> ans(2, 0);

        ans[0] = pq.top().second.first;
        ans[1] = pq.top().second.second;

        return ans;
    }
};