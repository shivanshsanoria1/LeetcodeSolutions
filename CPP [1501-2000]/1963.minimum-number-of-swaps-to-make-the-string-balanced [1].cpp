class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minSwaps(string s) {
        // count of '[' and ']' without their matching partners
        int unpairedLeft = 0;
        int unpairedRight = 0;

        for(char ch: s)
        {
            if(ch == ']')
            {
                if(unpairedLeft > 0)
                    unpairedLeft--;
                else
                    unpairedRight++;
            }
            else // ch == '['
                unpairedLeft++;
        }

        // at this point: unpairedLeft == unpairedRight

        return unpairedRight % 2 == 0 ? unpairedRight/2 : (unpairedRight + 1)/2;
    }
};

/*
# each swap balances out 2 pairs of '[' and ']'
# suppose after eliminating the balanced brackets, 
  we are left with:

# Case 1: even imbalanced pairs (4 in this case)
  ]]]] ... [[[[
  swapping the first ']' with the last '[', we get:
  []]] ... [[[]
  removing the balanced pairs, we get:
  ]] ... [[
  repeating the above process again balances the entire string
  thus, for 4 imbalances we needed 2 swaps
  # in general, for even n imbalances, n/2 swaps are needed

# Case 2: odd imbalanced pairs (3 in this case)
  ]]] ... [[[
  swapping the first ']' with the last '[', we get:
  []] ... [[]
  removing the balanced pairs, we get:
  ] ... [
  now swapping the leftover ']' and '[' balances the entire string
  thus, for 3 imbalances we needed 2 swaps
  # in general, for odd n imbalances, (n+1)/2 swaps are needed
*/