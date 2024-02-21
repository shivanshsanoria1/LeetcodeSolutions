class Solution {
public:
    static bool cmp(string& s1, string& s2) {
        return s1 + s2 >= s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        int zeros = 0;
        vector<string> strNums;
        for(int num: nums)
        {
            if(num == 0)
                zeros++;
            strNums.push_back(to_string(num));
        }
        // the case where all elements in array are 0
        if(zeros == nums.size()) 
            return "0";
        sort(strNums.begin(), strNums.end(), cmp);
        string ans = "";
        for(string& str: strNums)
            ans += str;
        return ans;
    }
};