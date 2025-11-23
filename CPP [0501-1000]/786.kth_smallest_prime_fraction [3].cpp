class Solution {
private:
    // {arr[i]/arr[j], {arr[i], arr[j]}}
    typedef pair<float, pair<int, int>> PFII;

public: 
    // T.C.=O((n^2)*log(n^2)), S.C.=O(n^2)
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) { 
        int n=arr.size();
        // min-heap
        priority_queue<PFII, vector<PFII>, greater<PFII>> pq; 

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)  
                pq.push({(float)arr[i]/arr[j], {arr[i], arr[j]}});

        vector<int> ans(2, 0);

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