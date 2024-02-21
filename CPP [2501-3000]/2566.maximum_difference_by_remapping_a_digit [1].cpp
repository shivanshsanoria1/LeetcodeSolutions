class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        for(char ch: str)
            if(ch != '9')
            {
                replace(str.begin(), str.end(), ch, '9');
                break;
            }
        int maxNum = stoi(str);

        str = to_string(num);
        char ch = str[0];
        replace(str.begin(), str.end(), ch, '0');
        int minNum = stoi(str);

        return maxNum - minNum;
    }
};
/*
# to make the max num: replace all occurences of the non-nine-MSB with 9
# to make the min num: replace all occurences of the MSB with 0
*/