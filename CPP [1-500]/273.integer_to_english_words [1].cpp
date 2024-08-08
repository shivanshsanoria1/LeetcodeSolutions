class Solution {
private:
    void initializeMap(unordered_map<int, string>& mp){
        mp[1] = "One";
        mp[2] = "Two";
        mp[3] = "Three";
        mp[4] = "Four";
        mp[5] = "Five";
        mp[6] = "Six";
        mp[7] = "Seven";
        mp[8] = "Eight";
        mp[9] = "Nine";

        mp[11] = "Eleven";
        mp[12] = "Twelve";
        mp[13] = "Thirteen";
        mp[14] = "Fourteen";
        mp[15] = "Fifteen";
        mp[16] = "Sixteen";
        mp[17] = "Seventeen";
        mp[18] = "Eighteen";
        mp[19] = "Nineteen";

        mp[10] = "Ten";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";
    }

    // converts a 3-digit num 'num3' into words
    string parse3digits(int num3, unordered_map<int, string>& mp){
        // word form of 'num3'
        string words3 = "";

        // hundreds digit
        int digit_100s = num3 / 100;
        if(digit_100s > 0)
            words3 += " " + mp[digit_100s] + " Hundred";

        // 2-digit num 'num2' extracted from 3-digit num 'num3'
        int num2 = num3 % 100;
        if(num2 == 0)
            return words3;
        
        // 1 <= num2 <= 19
        if(num2 < 20)
        {
            words3 += " " + mp[num2];
            return words3;
        }
        
        // 20 <= num2 <= 99
        // tens and ones digit
        int digit_10s = num2 / 10;
        int digit_1s = num2 % 10;

        if(digit_10s > 0)
            words3 += " " + mp[10 * digit_10s];
        if(digit_1s > 0)
            words3 +=  " " + mp[digit_1s];

        return words3;
    }

public:
    // T.C.=O(d), S.C.=O(1)
    // d: digits in 'num' which is log10(num)
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        
        unordered_map<int, string> mp;
        initializeMap(mp);

        vector<string> suffixes = {"", " Thousand", " Million", " Billion"};
        vector<string> groups3;
        for(int i=0; num > 0 && i<4; num /= 1000, i++)
        {
            int num3 = num % 1000;
            string words3 = parse3digits(num3, mp);
            if(num3 > 0)
                words3 += suffixes[i];

            groups3.push_back(words3);
        }

        reverse(groups3.begin(), groups3.end());
        string ans = "";
        for(string& word3: groups3)
            ans += word3;

        // remove the leading space
        return ans.substr(1);
    }
};