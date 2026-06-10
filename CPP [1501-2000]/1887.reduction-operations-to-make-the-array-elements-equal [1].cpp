class Solution {
public:
    int reductionOperations(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(n)
        map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;

        int mul = 0;
        int op = 0;
        for(auto [num, freq]: mp)
        {
            op += freq * mul;
            mul++;
        }
        return op;
    }
};