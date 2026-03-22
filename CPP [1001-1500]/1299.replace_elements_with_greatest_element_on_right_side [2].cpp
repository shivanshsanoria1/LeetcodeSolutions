class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) { //T.C.=O(n) , S.C.=O(1)
        int n=arr.size();
        vector<int> ans(n);
        int max_right=arr[n-1]; //assume last element to be max
        for(int i=n-2; i>=0; i--) //iterate array in reverse
        {
            ans[i]=max_right;
            max_right=max(max_right,arr[i]); //update max right if needed
        }
        ans[n-1]=-1; //last element has no max element to its right
        return ans;
    }
};