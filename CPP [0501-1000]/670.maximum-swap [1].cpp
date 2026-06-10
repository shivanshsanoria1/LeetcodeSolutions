class Solution {
public:
    // T.C.=O(d^2), S.C.=O(d)
    // d: max num of digits in num, (limited to 9 here)
    // Greedy
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        for(int i=0; i<n-1; i++)
        {
            char maxDigit = s[i];
            int idx = -1;
            
            for(int j=n-1; j>i; j--)
                if(s[j] > maxDigit)
                {
                    maxDigit = s[j];
                    idx = j;
                }

            if(idx != -1)
            {
                swap(s[i], s[idx]);
                break;
            }
        }

        return stoi(s);
    }
};

// for each digit at index i, find the max digit to the right of it,
// in case there are multiple max digits choose the rightmost one