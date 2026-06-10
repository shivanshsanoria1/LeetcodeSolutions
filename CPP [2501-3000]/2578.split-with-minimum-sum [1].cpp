class Solution {
public:
    int splitNum(int num) {
        vector<int> freq(10, 0);
        while(num > 0)
        {
            freq[num % 10]++;
            num /= 10;
        }

        string n1 = "", n2 = "";
        bool flag = true;
        for(int i=1; i<=9; i++)
            while(freq[i] > 0)
            {
                if(flag)
                    n1 += to_string(i);
                else
                    n2 += to_string(i);
                flag = !flag; // flip the flag
                freq[i]--;
            }
        return n2.length() == 0 ? stoi(n1) : stoi(n1) + stoi(n2);
    }
};
/*
# to ensure the sum of the 2 splitted nums stays min, all the 0's in the original num are ignored,
  or can be assumed to be leading 0's in the 2 splitted nums
*/