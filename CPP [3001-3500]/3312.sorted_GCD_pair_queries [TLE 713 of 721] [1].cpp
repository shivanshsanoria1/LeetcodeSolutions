class Solution {
public:
    // T.C.=O(n^2*log(m) + n^2*log(n^2) + q), S.C.=O(n^2)
    // m: max-val in nums[]
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        vector<int> gcds;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                gcds.push_back(__gcd(nums[i], nums[j]));
        
        sort(gcds.begin(), gcds.end());

        vector<int> ans;
        for(long long int idx: queries)
            ans.push_back(gcds[idx]);
        
        return ans;
    }
};