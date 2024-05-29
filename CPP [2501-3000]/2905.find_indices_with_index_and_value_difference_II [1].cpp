class Solution {
public:
    // T.C.=O(??), S.C.=O(n)
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n=nums.size();

        // pair each value with its index
        vector<pair<int, int>> pairs;
        for(int i=0; i<n; i++)
            pairs.push_back({nums[i], i});

        // sort in increasing order of value and
        // in increasing order of index (if values are equal)
        sort(pairs.begin(), pairs.end());

        vector<int> ans(2, -1);
        
        for(int i=0; i<n; i++)
        {
            // Step 1: Binary-search in index-range [i, n-1] in pairs[]

            int left = i, right = n-1;
            // index of the first pair in pairs[] such that
            // 'value of pair at idx' - 'value of pair at i' >= 'valueDifference'
            int idx = -1;

            while(left <= right)
            {
                int mid = left + (right - left)/2;

                if(pairs[mid].first - pairs[i].first >= valueDifference)
                {
                    idx = mid;
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }

            // idx not found
            if(idx == -1)
                continue;

            // Step 2: Linear-search in index-range [idx, n-1] in pairs[]

            // for the index range [idx, n-1] in pairs[] check if the 
            // diff of original index ie, index in nums [] for pairs >= 'indexDifference'
            for(int j=idx; j<n; j++)
                if(abs(pairs[j].second - pairs[i].second) >= indexDifference)
                {
                    ans[0] = pairs[i].second;
                    ans[1] = pairs[j].second;
                    return ans;
                }
        }

        return ans;
    }
};