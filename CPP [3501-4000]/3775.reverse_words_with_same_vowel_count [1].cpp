class Solution {
private:
    int findVowelCount(string& s){
        int count = 0;
        for(char ch: s)
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                count++;
        
        return count;
    }

public:
    // T.C.=O(n), S.C.=O(n)
    string reverseWords(string s) {
        istringstream iss(s);
        string word = "";
        int vowelCount1 = -1;
        string ans = "";

        while(iss >> word){
            if(vowelCount1 == -1)
                vowelCount1 = findVowelCount(word);
            else if(findVowelCount(word) == vowelCount1)
                reverse(word.begin(), word.end());
            
            ans += word + " ";
        }

        ans.pop_back();
        return ans;
    }
};