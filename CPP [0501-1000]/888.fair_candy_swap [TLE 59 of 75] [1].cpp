class Solution {
public:
    vector<int> fairCandySwap(vector<int>& arr1, vector<int>& arr2) { // T.C.=O(n^2), S.C.=O(1)
        int sum1 = accumulate(arr1.begin(), arr1.end(), 0);
        int sum2 = accumulate(arr2.begin(), arr2.end(), 0);
        vector<int> ans(2);
        for(int i=0; i<arr1.size(); i++)
            for(int j=0; j<arr2.size(); j++)
                if(sum1 - arr1[i] + arr2[j] == sum2 - arr2[j] + arr1[i])
                {
                    ans[0] = arr1[i];
                    ans[1] = arr2[j];
                }
        return ans;
    }
};