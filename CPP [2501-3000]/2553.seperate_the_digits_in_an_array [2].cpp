class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num: nums)
        {
            string str = to_string(num);
            for(char c: str)
                ans.push_back(c - '0');
        }
        return ans;
    }
};