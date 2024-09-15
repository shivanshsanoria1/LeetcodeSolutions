class Solution {
public:
    // T.C.=O(n^3*logn), S.C.=O(n)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        set<vector<int>> triplets;

        int n=nums.size();
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                    if(nums[i] + nums[j] + nums[k] == 0)
                        triplets.insert({nums[i], nums[j], nums[k]});
        
        vector<vector<int>> ans;
        for(vector<int> triplet: triplets)
            ans.push_back({triplet[0], triplet[1], triplet[2]});

        return ans;
    }
};