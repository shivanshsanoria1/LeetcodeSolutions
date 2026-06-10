class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> temp;
        for(int i=0; i<n; i++)
            temp.push_back({nums[i], i});
        
        sort(temp.begin(), temp.end());

        int maxIdx = temp[n-1].second;
        int maxWidth = 0;

        for(int i=n-2; i>=0; i--)
        {
            int idx = temp[i].second;

            maxIdx = max(maxIdx, idx);
            maxWidth = max(maxWidth, maxIdx - idx);
        }
        
        return maxWidth;
    }
};

// similar: [739. daily-temperatures]