class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    // T.C.=O(n), S.C.=O(1)
    long long countVowels(string word) {
        long long int count = 0;
        long long int n=word.length();

        for(int i=0; i<n; i++)
            if(isVowel(word[i]))
                count += (n-i) * (i+1);
                
        return count;
    }
};
/*
Eg- string: "ABCDE" (n = 5)

# substrings starting at index 0
  A
  AB
  ABC
  ABCD
  ABCDE
# substrings starting at index 1
  B
  BC
  BCD
  BCDE
# substrings starting at index 2
  C
  CD
  CDE
# substrings starting at index 3
  D
  DE
# substrings starting at index 4
  E

# total freq of each char in all the substrings:
  A -> 5*1 = 5
  B -> 4*2 = 8
  C -> 3*3 = 9
  D -> 2*4 = 8
  E -> 1*5 = 5

# thus, total freq of an element at index i in all the substrings 
  = (num * pos)
  = (n-i) * (i+1)
  where,
  num: number of substrings starting at index i
  pos: position of the curr element (1 indexed)
*/