class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> mp; // digit sum -> freq
        for(int i=lowLimit; i<=highLimit; i++)
            mp[digitSum(i)]++;
        int ans = 0;
        for(auto it: mp)
            ans = max(ans, it.second);
        return ans;
    }
};