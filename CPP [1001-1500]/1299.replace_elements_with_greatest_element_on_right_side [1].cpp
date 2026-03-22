class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) { //T.C.=O(n^2) , S.C.=O(1)
        int n=arr.size();
        vector<int> ans(n);
        for(int i=0; i<n-1; i++)
        {
            int max_right=INT_MIN;
            for(int j=i+1; j<n; j++) //find max element to the right
                max_right=max(max_right,arr[j]);
            ans[i]=max_right;
        }
        ans[n-1]=-1; //last element has no max element to its right
        return ans;
    }
};