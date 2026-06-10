class Solution {
private:
    static bool cmp(int& a, int& b){
        return to_string(a) < to_string(b);
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    int findKthNumber(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++)
            nums.push_back(i);
        
        sort(nums.begin(), nums.end(), cmp);

        return nums[k-1];
    }
};