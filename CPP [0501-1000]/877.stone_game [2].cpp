class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
/*
# given: n is even, so n-1 is odd
# array indexes along with their parities:
  0, 1, 2, 3, ..., n-3, n-2, n-1
  E, O, E, O, ..., O,   E,   O
# A can either start by picking either 
  the even index 0 or the odd index n-1
  # if A picks the even index 0:
    then B can only odd indexes 1 or n-1
  # if A picks the odd index n-1:
    then B can only even indexes 0 or n-2
# observing the pattern:
  A can always pick either all the even or odd indexes
  and since sum(even indexed values) != sum(odd indexed values)
  A can just pick whichever one is larger and win the game
*/