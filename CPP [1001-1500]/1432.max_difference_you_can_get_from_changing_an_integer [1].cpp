class Solution {
public:
    // T.C.=O(9^3), S.C.=O(9)
    // Brute-Force
    int maxDiff(int num) {
        string str = to_string(num);
        int maxNum = num;
        int minNum = num;

        for(char ch: str)
            for(char i='0'; i<='9'; i++)
            {
                string temp = str;
                replace(temp.begin(), temp.end(), ch, i);

                if(temp[0] == '0')
                    continue;

                maxNum = max(maxNum, stoi(temp));
                minNum = min(minNum, stoi(temp));
            }
        
        return maxNum - minNum;
    }
};