class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int possibleStringCount(string word) {
        int count = 1;
        for(int i=1; i<word.length(); i++)
            if(word[i-1] == word[i])
                count++;

        return count;
    }
};

/*
# for each group of same consecutive chars of size g,
  the num of possible strings increases by g-1
#  count is started at 1 since the given string 
  is also one of the possible strings
*/