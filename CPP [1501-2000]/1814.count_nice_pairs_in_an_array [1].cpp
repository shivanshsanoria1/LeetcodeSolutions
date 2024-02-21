class Solution {
private:
    #define MOD int(1e9 + 7)

    int rev(int n){
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
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