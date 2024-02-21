class Solution {
public:
    static bool cmp(int& a, int& b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        // the case where all elements in array are 0
        if(nums[0] == 0 && nums.back() == 0)
            return "0";
        string ans = "";
        for(int num: nums)
            ans += to_string(num);
        return ans;
    }
};