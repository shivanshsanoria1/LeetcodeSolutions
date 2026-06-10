class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    // T.C.=O(n), S.C.=O(1)
    // Greedy
    bool doesAliceWin(string s) {
        for(char ch: s)
            if(isVowel(ch))
                return true;

        return false;
    }
};
/*
# Case 1: original string has odd (2V+1) vowels

  # Step 1:
    Alice simply removes the entire string

  # Step 2:
    Bob is left with an empty string
  
  Conclusion: Bob loses and Alice wins

------------------------------

# Case 2: original string has even (0) vowels
  # Step 1:
    Alice cannot remove any substring
  
  Conclusion: Alice loses and Bob wins

------------------------------

# Case 3: original string has even (2V) vowels

  # Step 1: 
    Alice removes the longest substring with (2V-1) vowels 
    starting from start or end of original string
    thus leaving a substring with only 1 vowel at index i, say Xi
    this would look something like this:
    [X0, x1, ..., X(i-1)] [Xi] [X(i+1), ..., X(n-2), X(n-1)]

    Alice can either remove the substring [0, i-1] or [i+1, n-1] 
    depending on which one has (2V-1) vowels

  # Step 2:
    Now Bob has only has the choice to remove either the part [i+1, n-1] or [0, i-1]
    depending on which one has 0 vowels

  # Step 3: 
    Alice is now left with the string [Xi] which only has 1 vowel 
    which she can simply remove as a whole
  
  # Step 4:
    Now Bob is left is empty string

  Conclusion: Bob loses and Alice wins

------------------------------

# From the above 3 cases:
  Alice always wins, unless the original has 0 vowels

*/