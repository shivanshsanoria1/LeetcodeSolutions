class Solution {
public:
    typedef pair<float, pair<int, int>> PI; // {arr[i]/arr[j], {arr[i], arr[j]}}

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) { // T.C.=O((n^2)*log(n^2)), S.C.=O(n^2)
        vector<int> ans(2, 0);
        int n = arr.size();
        vector<PI> vec;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)  
                vec.push_back({(float)arr[i]/arr[j], {arr[i], arr[j]}});
        sort(vec.begin(), vec.end());
        ans[0] = vec[k-1].second.first;
        ans[1] = vec[k-1].second.second;
        return ans;
    }
};