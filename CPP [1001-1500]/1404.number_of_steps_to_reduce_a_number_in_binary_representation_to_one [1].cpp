class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    // Simulation
    int numSteps(string s) {
        int steps = 0;

        while(s.length() > 1)
        {
            if(s.back() == '0')
                s.pop_back();
            else
            {
                reverse(s.begin(), s.end());
                // initial carry-bit is set to 1 to simulate adding 1 to the num
                int carry = 1;

                for(int i=0; i<s.length() && carry == 1; i++)
                {
                    int bit = s[i] - '0';
                    s[i] = (bit + carry) % 2 + '0';
                    carry = (bit + carry) / 2;
                }

                // final carry 1 means a new MSB is generated
                if(carry == 1)
                    s += "1";

                reverse(s.begin(), s.end());
            }

            steps++;
        }

        return steps;
    }
};
/*
# if num is even, then divide it by 2, ie, right-shift by 1
# if num is odd, then add 1 to it
# check the LSB (Least Significant Bit), ie, rightmost bit
# LSB = 0 means even
# LSB = 1 means odd
# even num requires just 1 step: dropping the LSB (rightmost-bit)
# odd num requires 2 steps: adding 1 to get an even num and then dropping the LSB
# similar to Collatz-conjecture
*/