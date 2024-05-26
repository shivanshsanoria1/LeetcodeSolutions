class Solution {
public:
    // T.C.=O(n + q), S.C.=O(n)
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        // stores the indexes where x appears in nums[]
        vector<int> idxs;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] == x)
                idxs.push_back(i);
        
        vector<int> ans;
        for(int query: queries)    
        {
            // convert the query-index to 0-based instead of 1-based
            query--;

            ans.push_back(query >= idxs.size() ? -1 : idxs[query]);
        }
        
        return ans;
    }
};