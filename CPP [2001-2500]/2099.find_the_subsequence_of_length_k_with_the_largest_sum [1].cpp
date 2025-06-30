class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(n*log(n) + k*log(k)), S.C.=O(n)
    vector<int> maxSubsequence(vector<int>& nums, int k) { 
        vector<PII> temp; // {num, idx}
        for(int i=0; i<nums.size(); i++)
            temp.push_back({nums[i], i});

        // sort in decreasing order of numeric value
        sort(temp.begin(), temp.end(), greater<PII>());

        // sort the first k pairs in increasing order of index
        sort(temp.begin(), temp.begin() + k, [](PII &a, PII &b){
            return a.second < b.second;
        });

        vector<int> ans;
        for(int i=0; i<k; i++)
            ans.push_back(temp[i].first);

        return ans;
    }
};