class Solution {
private:
    void solve(int n, vector<int>& nums, int num){
        if(num > n)
            return;

        if(num > 0)    
            nums.push_back(num);

        for(int i = num == 0 ? 1 : 0; i <= 9; i++)
            solve(n, nums, num*10 + i);
    }

public:
    // T.C.=O(n), S.C.=O(log10(n))
    vector<int> lexicalOrder(int n) {
        vector<int> nums;
        solve(n, nums, 0);

        return nums;
    }
};