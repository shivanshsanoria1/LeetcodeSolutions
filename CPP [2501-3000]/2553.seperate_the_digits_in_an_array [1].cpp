class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num: nums)
        {
            vector<int> temp;
            while(num > 0)
            {
                temp.push_back(num % 10);
                num /= 10;
            }
            for(int i=temp.size()-1; i>=0; i--)
                ans.push_back(temp[i]);
        }
        return ans;
    }
};