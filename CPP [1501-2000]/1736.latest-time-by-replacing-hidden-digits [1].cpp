class Solution {
public:
    string maximumTime(string time) {
        string ans = time;
        if(time[4] == '?')
            ans[4] = '9';
        if(time[3] == '?')
            ans[3] = '5';
        if(time[0] != '?' && time[1] == '?')
            ans[1] = time[0] == '2' ? '3' : '9';
        if(time[0] == '?' && time[1] != '?')
            ans[0] = time[1] <= '3' ? '2' : '1';
        if(time[0] == '?' && time[1] == '?')
        {
            ans[1] = '3';
            ans[0] = '2';
        }
        return ans;
    }
};