class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool> ans(m, true);
        for(int i=0; i<m; i++)
        {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());
            for(int j=1; j<temp.size()-1; j++)
                if(temp[j] - temp[j-1] != temp[j+1] - temp[j])
                {
                    ans[i] = false;
                    break;
                }
        }
        return ans;
    }
};
// T.C.=O(m*n*logn), S.C.=O(n)