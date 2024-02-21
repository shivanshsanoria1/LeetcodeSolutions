class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) { // T.C.=O((n^2)*log(n^2)), S.C.=O(n^2)
        int n = nums.size();
        vector<int> dist;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                dist.push_back(abs(nums[i] - nums[j]));
        sort(dist.begin(), dist.end());
        return dist[k-1];
    }
};