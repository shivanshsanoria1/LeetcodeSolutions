class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    int countOrders(int n) {
        long long int ans = 1;
        for(int slots = 2*n; slots > 0; slots -= 2)
            ans = (ans * (slots*(slots-1)) / 2) % MOD;
        return ans;
    }
};