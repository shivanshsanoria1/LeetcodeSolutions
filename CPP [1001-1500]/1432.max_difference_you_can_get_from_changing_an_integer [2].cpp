class Solution {
public:
    // T.C.=O(9), S.C.=O(9)
    // Greedy
    int maxDiff(int num) {
        string maxStr = to_string(num);
        for(char ch: maxStr)
        {
            if(ch == '9')
                continue;
            
            replace(maxStr.begin(), maxStr.end(), ch, '9');
            break;
        }
        int maxNum = stoi(maxStr);

        string minStr = to_string(num);
        char msd = minStr[0];
        replace(minStr.begin(), minStr.end(), msd, '1');
        int minNum = stoi(minStr);

        minStr = to_string(num);
        for(int i=1; i<minStr.length(); i++)
        {
            char ch = minStr[i];

            if(ch == '0' || ch == msd)
                continue;
            
            replace(minStr.begin(), minStr.end(), ch, '0');
            break;
        }
        minNum = min(minNum, stoi(minStr));

        return maxNum - minNum;
    }
};

/*
# MSD: Most Significant Digit
# to generate the max-num:
    replace all ocurences of the most significant non-nine digit with 9
# to generate the min-num:
  # replace all ocurences of MSD with 1
    OR
  # replace all ocurences of the most significant non-zero and non-MSD digit with 0
*/