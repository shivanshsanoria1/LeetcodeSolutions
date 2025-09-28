class Solution {
public:
    // T.C.=O(log(n)), S.C.=O(1)
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        for(int mul = 1; n > 0; n /= 10){
            int rem = n % 10;
            if(rem > 0)
                ans.push_back(rem * mul);
                
            if(mul <= INT_MAX/10)
                mul *= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};