class Solution {
public:
    void clearVisited(vector<bool> &lowerVisited, vector<bool> &upperVisited){
        for(int i=0; i<26; i++)
        {
            lowerVisited[i] = false;
            upperVisited[i] = false;
        }
    }

    string solve(vector<bool> &lowerVisited, vector<bool> &upperVisited, string &s, int start, int end){
        int len = end - start + 1;
        if(len < 2)
            return "";
        // mark chars of the curr string in the visited vectors
        for(int i=start; i<=end; i++) 
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                lowerVisited[s[i] - 'a'] = true;
            else
                upperVisited[s[i] - 'A'] = true;
        }
        for(int i=start; i<=end; i++)
        {   
            int idx = (s[i] >= 'a' && s[i] <= 'z') ? s[i] - 'a' : s[i] - 'A';
            // find a char which does not have its lower or upper case counterpart
            if(!lowerVisited[idx] != !upperVisited[idx]) // logical XOR- !a != !b
            {
                clearVisited(lowerVisited, upperVisited); 
                string s1 = solve(lowerVisited, upperVisited, s, start, i-1);
                clearVisited(lowerVisited, upperVisited);
                string s2 = solve(lowerVisited, upperVisited, s, i+1, end);
                return s1.length() >= s2.length() ? s1 : s2;
            }
        }
        // clear the visited vectors for the next recursive call
        clearVisited(lowerVisited, upperVisited);
        return s.substr(start, len); // curr string is 'Nice'
    }

    string longestNiceSubstring(string s) { // Divide-and-Conquer
        vector<bool> lowerVisited(26, false); // lowercase letters
        vector<bool> upperVisited(26, false); // uppercase letters
        return solve(lowerVisited, upperVisited, s, 0, s.length()-1);
    }
};
/*
# find the char (at index i) at each step which does not have its lower or upper case counterpart, ie,
lowerVisited[idx] = true and upperVisited[idx] = false or 
lowerVisited[idx] = false and upperVisited[idx] = true
# then divide the string into 2 parts- [start, i-1] and [i+1, end] recursively
# return the longer string found
# if no such char is found in the curr string then the curr string is 'Nice' so just return it
*/