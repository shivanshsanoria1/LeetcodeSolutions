class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) { // T.C.=O(n^2), S.C.=O(n)
        if(x == 0)
            return 0;
            
        vector<pair<int, int>> vec; // {nums[i], i}
        for(int i=0; i<nums.size(); i++)
            vec.push_back({nums[i], i});
        sort(vec.begin(), vec.end());

        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++)
            for(int j=i+1; j<nums.size(); j++)
                if(abs(vec[i].second - vec[j].second) >= x)
                {
                    ans = min(ans, abs(vec[i].first - vec[j].first));
                    break;
                }
        return ans;
    }
};