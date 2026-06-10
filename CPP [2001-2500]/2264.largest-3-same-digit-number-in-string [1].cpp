class Solution {
public:
    string largestGoodInteger(string num) {
        int left = 0, right = 2;
        string ans = "";
        while(right < num.length())
        {
            if(num[left] == num[left + 1] && num[left + 1] == num[right])
                ans = max(ans, num.substr(left, 3));
            left++;
            right++;
        }
        return ans;
    }
};