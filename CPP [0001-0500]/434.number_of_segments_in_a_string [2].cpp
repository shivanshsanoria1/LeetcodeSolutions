class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        istringstream ss(s);
        string word = "";
        while(ss >> word)
            count++;
        return count;
    }
};