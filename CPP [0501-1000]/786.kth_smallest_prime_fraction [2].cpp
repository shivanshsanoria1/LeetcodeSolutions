class Solution {
public:
    // T.C.=O((n^2)*log(n^2)), S.C.=O(n^2)
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) { 
        // arr[i] / arr[j] -> {arr[i], arr[j]}
        multimap<float, pair<int, int>> mp;

        int n=arr.size();
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)  
                mp.insert({(float)arr[i] / arr[j], {arr[i], arr[j]}});

        auto itr = mp.begin();
        advance(itr, k-1);

        vector<int> ans(2, 0);

        ans[0] = itr->second.first;
        ans[1] = itr->second.second;

        return ans;
    }
};