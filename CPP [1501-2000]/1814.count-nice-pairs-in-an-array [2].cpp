class Solution {
private:
    #define MOD int(1e9 + 7)

    int rev(int n){
        int rev_n = 0;
        while(n > 0)
        {
            rev_n = rev_n * 10 + n % 10;
            n /= 10;
        }
        return rev_n;
    }

public:
    int countNicePairs(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> mp;
        for(int num: nums)
            mp[num - rev(num)]++;
        
        int count = 0;
        for(auto it: mp)
        {
            long long int freq = it.second;
            count = (count + ((freq - 1)*freq)/2) % MOD;
        }
        return count;
    }
};