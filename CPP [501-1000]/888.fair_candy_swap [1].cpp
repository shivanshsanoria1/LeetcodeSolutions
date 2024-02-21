class Solution {
public:
    vector<int> fairCandySwap(vector<int>& arr1, vector<int>& arr2) { // T.C.=O(n1 + n2), S.C.=O(n2)
        int sum1 = accumulate(arr1.begin(), arr1.end(), 0);
        int sum2 = accumulate(arr2.begin(), arr2.end(), 0);
        int sum = (sum1 + sum2) / 2;
        int diff1 = sum - sum1;
        unordered_set<int> s2(arr2.begin(), arr2.end());
        vector<int> ans(2);
        for(int num: arr1)
            if(s2.find(num + diff1) != s2.end())
            {
                ans[0] = num;
                ans[1] = num + diff1;
                break;
            }
        return ans;
    }
};