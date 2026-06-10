class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    int minMaxDifference(int num) {
        string str = to_string(num);
        for(char ch: str)
        {
            if(ch == '9')
                continue;

            replace(str.begin(), str.end(), ch, '9');
            break;
        }
        int maxNum = stoi(str);

        str = to_string(num);
        char msd = str[0];
        replace(str.begin(), str.end(), msd, '0');
        int minNum = stoi(str);

        return maxNum - minNum;
    }
};

/*
# MSD: Most Significant Digit

# to make the max num: 
    replace all occurences of the non-nine-MSD with 9
# to make the min num: 
    replace all occurences of the MSD with 0

# replace(s.begin(), s.end(), ch1, ch2):
    replaces all occurences of ch1 with ch2 in s
*/