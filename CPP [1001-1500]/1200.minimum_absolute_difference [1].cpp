class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) { //T.C.=O(nlogn)
        vector<vector<int>> ans;
        int n=arr.size(), min_diff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=1; i<n; i++)
            min_diff=min(min_diff,arr[i]-arr[i-1]);
        for(int i=0; i<n-1; i++)
        {
            if(arr[i]+min_diff == arr[i+1])
            {
                vector<int> pair(2);
                pair[0]=arr[i];
                pair[1]=arr[i+1];
                ans.push_back(pair);
            }
        }
        return ans;
    }
};