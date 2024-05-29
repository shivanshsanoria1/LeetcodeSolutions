class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Greedy
    int numSteps(string s) {
        int carry = 0;
        int steps = 0;

        for(int i=s.length()-1; i>0; i--)
        {
            int bit = s[i] - '0';

            if((bit + carry) % 2 == 0)
                steps++;
            else
            {
                carry = 1;
                steps += 2;
            }
        }

        return carry == 1 ? 1 + steps : steps;
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
# if a final carry is generated then MSB + carry == 2, 
  since MSB of input string is guranteed to be 1, 
  so 1 more step is required for this even num 
# similar to Collatz-conjecture
*/