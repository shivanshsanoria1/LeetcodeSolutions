class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) { //T.C.=O(nlogn)
        vector<vector<int>> ans;
        int n=arr.size(), min_diff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=1; i<n; i++)
        {
            int diff=arr[i]-arr[i-1];
            if(diff > min_diff)
                continue;
            if(diff < min_diff) //new min diff found
            {
                min_diff=diff; //update the min diff
                ans.clear(); //clear the ans vector
            }
            ans.push_back({arr[i-1],arr[i]}); //add pair to the ans vector
        }
        return ans;
    }
};