class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n^2)
    int smallestDistancePair(vector<int>& nums, int k) { 
        int n=nums.size();
        vector<int> dist;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                dist.push_back(abs(nums[i] - nums[j]));

        nth_element(dist.begin(), dist.begin() + k-1, dist.end());
        
        return dist[k-1];
    }
};