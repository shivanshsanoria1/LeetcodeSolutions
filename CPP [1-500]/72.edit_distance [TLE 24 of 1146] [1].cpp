class Solution {
public:
    int solve(string& s1, string& s2, int i, int j){
        int n1=s1.length(), n2=s2.length();
        if(i == n1 && j == n2) // both i and j index out of bounds
            return 0;
        if(i == n1) // only i index out of bounds
            return n2-j;
        if(j == n2) // only j index out of bounds
            return n1-i;
        if(s1[i] == s2[j]) // matching chars found
            return solve(s1, s2, i+1, j+1);
        int insert = solve(s1, s2, i, j+1);
        int remove = solve(s1, s2, i+1, j);
        int replace = solve(s1, s2, i+1, j+1);
        return 1 + min(insert, min(remove, replace));
    }

    int minDistance(string word1, string word2) { // Recursion
        return solve(word1, word2, 0, 0);
    }
};