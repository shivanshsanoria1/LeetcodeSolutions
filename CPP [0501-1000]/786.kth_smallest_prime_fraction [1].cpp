class Solution {
private:
    // {arr[i]/arr[j], {arr[i], arr[j]}}
    typedef pair<float, pair<int, int>> PFII;

public: 
    // T.C.=O((n^2)*log(n^2)), S.C.=O(n^2)
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) { 
        int n=arr.size();
        vector<PFII> vec;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)  
                vec.push_back({(float)arr[i]/arr[j], {arr[i], arr[j]}});

        sort(vec.begin(), vec.end());

        vector<int> ans(2, 0);

        ans[0] = vec[k-1].second.first;
        ans[1] = vec[k-1].second.second;

        return ans;
    }
};