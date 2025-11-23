class Solution {
private:
    void solve(vector<int>& nums, set<vector<int>>& subseqs, vector<int>& subseq, int i){
        if(i >= nums.size())
        {
            if(subseq.size() >= 2)
                subseqs.insert(subseq);
            return;
        }

        // exclude the element at index i
        solve(nums, subseqs, subseq, i+1);

        // include the element at index i
        if(subseq.empty() || subseq.back() <= nums[i])
        {
            subseq.push_back(nums[i]);
            solve(nums, subseqs, subseq, i+1);
            subseq.pop_back();
        }
    }

public:
    // T.C.=O((n*2^n)*log(n*2^n)), S.C.=O(n*2^n)
    // Backtracking
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> subseqs;
        vector<int> subseq;
        solve(nums, subseqs, subseq, 0);

        vector<vector<int>> ans(subseqs.begin(), subseqs.end());
        return ans;
    }
};