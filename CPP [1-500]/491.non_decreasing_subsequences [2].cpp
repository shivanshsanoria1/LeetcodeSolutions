class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& subseqs, vector<int>& subseq, int i){
        if(i >= nums.size())
        {
            if(subseq.size() >= 2)
                subseqs.push_back(subseq);
            return;
        }

        // exclude the element at index i
        if(subseq.empty() || subseq.back() != nums[i])
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
    // T.C.=O(n*2^n), S.C.=O(n)
    // Backtracking
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> subseqs;
        vector<int> subseq;
        solve(nums, subseqs, subseq, 0);

        return subseqs;
    }
};