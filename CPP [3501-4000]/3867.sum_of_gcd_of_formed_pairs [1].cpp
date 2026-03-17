class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int maxNum = nums[0];
        for(int num: nums){
            maxNum = max(maxNum, num);
            prefixGcd.push_back(gcd(num, maxNum));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        for(int left=0, right=prefixGcd.size()-1; left < right; left++, right--)
            sum += gcd(prefixGcd[left], prefixGcd[right]);
        
        return sum;
    }
};