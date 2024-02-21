class Solution {
private:
    #define MOD int(1e9 + 7)

    int rev(int n){
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
    }

public:
    int countNicePairs(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int count = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]))
                    count = (count + 1) % MOD;
        return count;
    }
};